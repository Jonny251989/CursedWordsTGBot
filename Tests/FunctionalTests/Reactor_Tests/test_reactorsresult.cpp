#include "test_reactorsresult.hpp"

size_t ReactorResultTest::count = 0;

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::SetUp() {
    std::string token = "7389966079:AAHXCquKT0JaQUqHRzac8MMsXMCUUd5uvXQ";
    t_bot = std::make_shared<TgBot::Bot>(token);
    shutdown_requested = false;
}


void ReactorResultTest::generator(){
    chat_id = -1002432345513;
    std::ifstream inputFile("./messages.txt");
    //std::ifstream inputFile("./Tests/FunctionalTests/Reactor_Tests/messages.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
    }
    std::string line;
    while (std::getline(inputFile, line)) {  
        auto message = t_bot->getApi().sendMessage(chat_id, line);
        send_messageId = message->messageId;
        std::cout<<"SEND MESSAGE WITH ID "<< message->messageId<<"\n";
        m_map[send_messageId];
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    inputFile.close();
    std::cout<<"Generator's works finished!\n";
}

void* thread_function(void* arg) {
    run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    return nullptr;
}

TEST_F(ReactorResultTest, FirstTest) {
    auto generator_f = [&](){
        generator();
    };

    pthread_t thread;
    pthread_create(&thread, nullptr, thread_function, nullptr);

    std::thread generatorThread{generator_f};     
    checker();
    pthread_kill(thread, SIGINT);

    pthread_join(thread, nullptr);

    for(auto it = m_map.begin(); it != m_map.end(); it++){
        EXPECT_EQ(std::abs(it->first - it ->second), 1);
    }
    generatorThread.join();
    pthread_join(thread, nullptr);
}

void ReactorResultTest::checker(){
    chat_id = -1002432345513;
    auto last_change_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>::zero();

    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        std::cout<<"GET ASNWER MESSAGE WITH ID "<< message->messageId<<"\n";
        last_change_time = std::chrono::steady_clock::now();
        answer_messageId = message->messageId;
        m_map[send_messageId] = answer_messageId;
    });
    try {
        TgBot::TgLongPoll longPoll( *t_bot);
        while (m_map.size() < size_map && elapsed_seconds.count() < limit_time) {
            elapsed_seconds = std::chrono::steady_clock::now() - last_change_time;
            std::cout<<"different times: "<<elapsed_seconds.count()<<", size of map: "<<m_map.size()<<"\n";
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}
