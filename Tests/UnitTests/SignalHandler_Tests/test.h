#pragma once

#include <gtest/gtest.h>
#include <condition_variable>
#include <mutex>
#include "signalhandler.hpp"

class SignalHandlerTest : public ::testing::Test {
protected:
    void test_callback();
    void send_signal(int signal);
    void wait_for_callback(int expected_count);
    void TearDown() override;
    std::atomic<int> callback_counter = 0;
    std::mutex mtx;
    std::condition_variable cv;
};