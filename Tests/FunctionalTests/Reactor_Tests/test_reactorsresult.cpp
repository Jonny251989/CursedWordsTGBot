#include "test_reactorsresult.hpp"

size_t ReactorResultTest::count = 0;

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::SetUp() {
    count = 0;
    std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";
    ptr_testing_bot = std::make_shared<TgBot::Bot>(token);
}

void ReactorResultTest::generator(){
    chat_id = -1002432345513;
    std::ifstream inputFile("./Tests/FunctionalTests/Reactor_Tests/messages.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return; 
    }
    
    std::string line;

    while (std::getline(inputFile, line)) {
        
        ptr_testing_bot->getApi().sendMessage(chat_id, line);
        m_map[line];
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    inputFile.close();

    ptr_testing_bot->getApi().sendMessage(chat_id, "Congratulations!Your TGBot works!\n");
}

TEST_F(ReactorResultTest, FirstTest) {
    auto generator_f = [&](){
        generator();//
    };
    auto checker_f = [&](){
        checker();
    };

    std::thread generatorThread{generator_f};
    generatorThread.join();
    run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    std::thread checkerThread{checker_f}; 
    checkerThread.join();
    //checker();


}

void ReactorResultTest::checker(){
    chat_id = -1002432345513;
    ptr_testing_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        count++;
        ptr_testing_bot->getApi().sendMessage(chat_id, "CHEKER" +std::to_string(count) + ": " + message->text);
    
        if (m_map.find(message->text) != m_map.end()) {
            m_map[message->text] = message->text;
        }
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