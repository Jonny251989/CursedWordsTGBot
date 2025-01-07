#include "test_reactorsresult.hpp"

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::SetUp() {
    std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";
    ptr_testing_bot = std::make_shared<TgBot::Bot>(token);
}

void ReactorResultTest::generator(){
    chat_id = -4709071415;
    std::ifstream inputFile("./Tests/FunctionalTests/Reactor_Tests/messages.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return; 
    }
    
    std::string line;
    while (std::getline(inputFile, line)) {
        ptr_testing_bot->getApi().sendMessage(chat_id, line);
        std::this_thread::sleep_for(std::chrono::seconds(9));
    }
    inputFile.close();

    ptr_testing_bot->getApi().sendMessage(chat_id, "Congratulations!Your TGBot works!\n");
}

TEST_F(ReactorResultTest, FirstTest) {
    auto testing_fun = [&](){
        generator();
    };
    std::thread testingThread{testing_fun};

    run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo"); 
    
    testingThread.join();
}

void ReactorResultTest::checker(){
    chat_id = -4673074190;
    ptr_testing_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
         ptr_testing_bot->getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        TgBot::TgLongPoll longPoll( *ptr_testing_bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}


void ReactorResultTest::testing_reactor(){
        TgBot::Bot bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
    });
    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        printf("User wrote %s\n", std::to_string(message->chat->id).c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}