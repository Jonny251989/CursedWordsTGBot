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
#include "logger.hpp"
#include <tgbot/tgbot.h>
#include "run_bot.hpp"
#include <chrono>
#include <pthread.h>
#include <csignal>

struct Message {
    std::int32_t  messageId_;
    std::string messageText_;
    Message(std::int32_t messageId, std::string messageText) 
        : messageId_(messageId), messageText_(std::move(messageText)) {}
};

class ReactorResultTest : public ::testing::Test {
protected:
    void SetUp() override {
        t_bot = std::make_shared<TgBot::Bot>(token_one);
        count_recieve_messages = 0;
        chat_id_ = -1002432345513;
    }

    void TearDown() override {}

    void generator() {
        std::ifstream inputFile(filePath);
        if (!inputFile) {
            Logger::getInstance().logInfo(Logger::Levels::Critical, "Не удалось открыть файл!\n");
            return;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            size_t last_space = line.find_last_of(' ');
            if (last_space == std::string::npos) continue;

            std::string flag_str = line.substr(last_space + 1);
            bool flag = (flag_str == "1");
            std::string clean_line = line.substr(0, last_space);

            {
                std::lock_guard<std::mutex> lock(set_mutex);
                message_container[clean_line] = flag;
            }

            t_bot->getApi().sendMessage(chat_id_, clean_line);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    void checker() {
        auto last_change_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds;

        t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            bool react_m = (message->text == "мат");
            ASSERT_EQ(message_container[message->replyToMessage->text], react_m);
            count_recieve_messages++;
            last_change_time = std::chrono::steady_clock::now();
        });

        try {
            TgBot::TgLongPoll longPoll(*t_bot);
            while (count_recieve_messages < limit_sent_messages_ && 
                   elapsed_seconds.count() < limit_time_in_sec) {
                longPoll.start();
                elapsed_seconds = std::chrono::steady_clock::now() - last_change_time;
            }
        } catch (const TgBot::TgException& e) {
            Logger::getInstance().logInfo(Logger::Levels::Critical, std::string("Error: ") + e.what());
        }
    }

private:
    std::atomic<size_t> count_recieve_messages{0};
    std::shared_ptr<TgBot::Bot> t_bot;
    std::int64_t chat_id_;
    const size_t limit_sent_messages_ = 5;
    const size_t limit_time_in_sec = 8;
    std::map<std::string, bool> message_container;
    std::mutex set_mutex;

    static const char* filePath;
    static std::string token_one;
};

const char* ReactorResultTest::filePath = "./bins/Tests/FunctionalTests/messages.txt";
std::string ReactorResultTest::token_one = "7212434431:AAFLuR1mQTqpageO7x575hkQzW7DzJTXdNs";
inline std::string token_two = "7763682966:AAEFBGifblSqB5of8cyS5WKjC6kK6pxTIuY";

TEST_F(ReactorResultTest, FirstTest) {
    std::jthread mainThread([&]() {
        run_bot(token_two);
    });

    generator();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::raise(SIGINT);
    checker();
}