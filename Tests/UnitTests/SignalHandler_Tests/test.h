#pragma once

#include <gtest/gtest.h>
#include <condition_variable>
#include <mutex>
#include "signalhandler.hpp"

std::atomic<int> callback_counter(0);
std::mutex mtx;
std::condition_variable cv;

// Коллбэк, который увеличивает счетчик и уведомляет условную переменную
void test_callback() {
    callback_counter.fetch_add(1, std::memory_order_relaxed);
    cv.notify_one();
}

class SignalHandlerTest : public ::testing::Test {
protected:
    SignalHandler* handler;

    // Метод для имитации сигнала
    void send_signal(int signal);

    // Метод для ожидания вызова коллбэка
    void wait_for_callback(int expected_count);

    // Метод для создания и инициализации SignalHandler
    void init_handler(const std::vector<int>& signals);

    void TearDown() override;

};