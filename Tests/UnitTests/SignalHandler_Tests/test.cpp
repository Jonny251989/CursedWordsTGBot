#include "test.h"

    // Метод для имитации сигнала
    void SignalHandlerTest::send_signal(int signal) {
        raise(signal);
    }

    // Метод для ожидания вызова коллбэка
    void SignalHandlerTest::wait_for_callback(int expected_count) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() { return callback_counter.load() == expected_count; });
    }

    // Метод для создания и инициализации SignalHandler
    void SignalHandlerTest::init_handler(const std::vector<int>& signals) {
        handler = new SignalHandler(signals, test_callback);
    }

    void SignalHandlerTest::TearDown() {
        delete handler;
    }

// Тест на вызов коллбэка при получении сигнала
TEST_F(SignalHandlerTest, CallbackIsInvokedOnSignal) {
    std::vector<int> signals = {SIGINT}; // например, используем сигнал SIGINT

    // Инициализация SignalHandler
    init_handler(signals);

    // Ожидаем, что коллбэк будет вызван
    send_signal(SIGINT);
    
    // Ожидаем уведомления, что коллбэк был вызван
    wait_for_callback(1);

    // Проверка, что коллбэк действительно был вызван
    ASSERT_EQ(callback_counter.load(), 1);
}

// Тест на повторную инициализацию SignalHandler (должен выбросить исключение)
TEST_F(SignalHandlerTest, ThrowExceptionOnSecondInitialization) {
    std::vector<int> signals = {SIGINT};

    // Инициализация первого обработчика
    init_handler(signals);

    // Попытка инициализировать второй обработчик - должно вызвать исключение
    ASSERT_THROW(init_handler(signals), std::runtime_error);
}

// Тест на правильное поведение при нескольких сигналах
TEST_F(SignalHandlerTest, MultipleSignalsInvocation) {
    std::vector<int> signals = {SIGINT, SIGTERM};

    // Инициализация SignalHandler
    init_handler(signals);

    // Отправка двух сигналов
    send_signal(SIGINT);
    send_signal(SIGTERM);

    // Ожидаем, что коллбэк будет вызван дважды
    wait_for_callback(2);

    // Проверка, что коллбэк был вызван дважды
    ASSERT_EQ(callback_counter.load(), 2);
}