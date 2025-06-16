#include <gtest/gtest.h>
#include <tgbot/tgbot.h>
#include <fstream>
#include <atomic>
#include <map>

class Checker : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
    void fill_map();
    void checker();

    std::atomic<size_t> count_recieve_messages{0};
    std::shared_ptr<TgBot::Bot> t_bot;
    std::int64_t chat_id_;
    const size_t limit_sent_messages_ = 5;
    const size_t limit_time_in_sec = 8;
    std::map<std::string, bool> message_container;
    std::mutex set_mutex;

    const char* filePath;
    std::string token_;
};