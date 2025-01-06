#include "test_reactorsresult.hpp"

void ReactorResultTest::SetUp() {
//7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ
std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";

ptr_testing_bot = std::make_shared<TgBot::Bot>(token);

// run_bot(token);

}

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::testing_reactor(){
    // std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";
    //     TgBot::Bot bot(token);
    ptr_testing_bot->getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
         ptr_testing_bot->getApi().sendMessage(message->chat->id, "Hi!");
    });
    ptr_testing_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        std::cout<<"Chat ID is "<<message->chat->id<<"\n";
         ptr_testing_bot->getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
    });
    try {
        printf("Bot username: %s\n",  ptr_testing_bot->getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll( *ptr_testing_bot);
        while (true) {
            printf("Long poll started\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

void ReactorResultTest::generator(){
    bool flag = true;
    ptr_testing_bot->getEvents().onCommand("start", [&](TgBot::Message::Ptr message) {
        
         ptr_testing_bot->getApi().sendMessage(message->chat->id, "Hi!");
         printf("ID chat: %s\n",  std::to_string(message->chat->id).c_str());
         ptr_testing_bot->getApi().sendMessage(message->chat->id, "ID chat: " + std::to_string(message->chat->id));
         flag = false;
         chat_id = message->chat->id;
    });
    TgBot::TgLongPoll longPoll( *ptr_testing_bot);
    while (flag) {
        printf("Long poll started\n");
        longPoll.start();
    }

    std::string message = "Yur testing bot is WORKING now";

    while(true){
        ptr_testing_bot->getApi().sendMessage(chat_id, "Your message is: " + message + "! Congratulations!\n");
        printf("Testing bot wrote: %s\n", (message + "! Congratulations!\n").c_str());
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

}

void ReactorResultTest::checker(){
    
}

TEST_F(ReactorResultTest, FirstTest) {
    auto testing_fun = [&](){
        generator();
    };
    std::thread testingThread{testing_fun};
    //testing_reactor();
    
    testingThread.join();

}