#pragma once

#include <gtest/gtest.h>
#include <memory>
#include <fstream>
#include <string>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <mutex>
#include <thread>
#include <experimental/random>
#include "task.hpp"
#include "queue.hpp"
#include <tgbot/tgbot.h>
#include "run_bot.hpp"
#include <chrono>
#include <pthread.h>
#include <csignal>


class ReactorResultTest : public ::testing::Test{

protected:
    void SetUp() override;
    void TearDown() override;

    void testing_reactor();
    void generator();
    void checker();
    std::int32_t send_messageId;
    std::int32_t answer_messageId;
    std::unordered_map<std::int32_t, std::int32_t> m_map;
    std::atomic<bool> shutdown_requested;
private:
    static size_t count;
    std::shared_ptr<TgBot::Bot> t_bot;
    std::int64_t chat_id;
    const size_t size_map = 10;
    const size_t limit_time = 10;
    
    //std::unordered_map<std::string, std::string> m_map;
};