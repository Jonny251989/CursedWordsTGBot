#include "test.h"

void SignalHandlerTest::send_signal(int signal) {
    raise(signal);
}

void SignalHandlerTest::test_callback() {
    callback_counter++;
    cv.notify_one();
}

void SignalHandlerTest::wait_for_callback(int expected_count) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return callback_counter.load() == expected_count; });
}

void SignalHandlerTest::TearDown() {
    
}

TEST_F(SignalHandlerTest, CallbackIsInvokedOnSignal) {

    std::vector<int> signals = {SIGINT, SIGTERM}; 
    SignalHandler signalHandler(signals, [&](){
        test_callback();
    });

    send_signal(SIGINT);
    wait_for_callback(1);

    ASSERT_EQ(callback_counter.load(), 1);
}

TEST_F(SignalHandlerTest, ThrowExceptionOnSecondInitialization) {
    std::vector<int> signals = {SIGINT};

    SignalHandler signalHandler(signals, [&](){
        test_callback();
    });

    ASSERT_THROW(SignalHandler(signals, [&](){ test_callback(); }), std::runtime_error);
}

// // Тест на правильное поведение при нескольких сигналах
TEST_F(SignalHandlerTest, MultipleSignalsInvocation) {

    std::vector<int> signals = {SIGINT, SIGTERM};
    SignalHandler signalHandler(signals, [&](){
        test_callback();
    });

    send_signal(SIGINT);
    send_signal(SIGTERM);
    wait_for_callback(2);

    ASSERT_EQ(callback_counter.load(), 2);
}