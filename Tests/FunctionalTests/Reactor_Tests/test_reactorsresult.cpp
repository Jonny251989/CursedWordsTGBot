#include "test_reactorsresult.hpp"

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::SetUp() {
    std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";
    t_bot = std::make_shared<TgBot::Bot>(token);
    shutdown_requested = false;
    count = 0;
}


void ReactorResultTest::generator(){
    chat_id = -1002432345513;
    //std::ifstream inputFile("./messages.txt");
    std::ifstream inputFile("./Tests/FunctionalTests/Reactor_Tests/messages.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
    }
    std::string line;
    while (std::getline(inputFile, line)) {  
        auto message = t_bot->getApi().sendMessage(chat_id, line);
        sent_message = line;
        count++;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    inputFile.close();
    std::cout<<"Generator's works finished!\n";
}

void ReactorResultTest::checker(){
    chat_id = -1002432345513;
    auto last_change_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>::zero();

    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        EXPECT_EQ(sent_message, message->replyToMessage->text);
        last_change_time = std::chrono::steady_clock::now();

    });
    try {
        TgBot::TgLongPoll longPoll( *t_bot);
        while (count < size_map && elapsed_seconds.count() < limit_time) {
            longPoll.start();
            elapsed_seconds = std::chrono::steady_clock::now() - last_change_time;
            std::cout<<"different times by int: "<<(int)(elapsed_seconds.count())<<"\ndifferent times by double: "<<elapsed_seconds.count()<<"\nsize of map: "<<count<<"\n";
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

TEST_F(ReactorResultTest, FirstTest) {
    auto generator_f = [&](){
        generator();
    };

    auto main_f = [&](){
        run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    };

    std::thread mainThread{main_f};
    std::thread generatorThread{generator_f};     
    checker();

    std::raise(SIGINT);

    generatorThread.join();
    mainThread.join();
}