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




class ReactorResultTest : public ::testing::Test{

protected:
    void SetUp() override;
    void TearDown() override;

    void testing_reactor();
    void generator();
    void checker();

private:
    std::shared_ptr<TgBot::Bot> ptr_testing_bot;
    std::int64_t chat_id;
};