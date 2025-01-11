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
    std::ifstream inputFile("./Tests/FunctionalTests/Reactor_Tests/messages.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return; 
    }
    std::string line;
    while (std::getline(inputFile, line)) {  
        t_bot->getApi().sendMessage(chat_id, line);
        gen_message = line;
        m_map[gen_message] = false;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    inputFile.close();
    std::cout<<"Generator works!\n";
    for(auto it = m_map.begin(); it != m_map.end(); it++){
        std::cout<<"key: "<<it->first<<", value: "<<it->second<<"\n";
    }
    shutdown_requested = true;
    kill(getpid(), SIGINT);
    kill(getpid(), SIGTERM);
}

TEST_F(ReactorResultTest, FirstTest) {
    // auto generator_f = [&](){
    //     generator();
    // };
    auto checker_f = [&](){
        checker();
    };
    auto main_f = [&](){
        run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    };
    std::thread mainThread{main_f};
    std::thread checkerThread{checker_f};     
    generator();
    checkerThread.join();
    mainThread.join();
}

void ReactorResultTest::checker(){
    chat_id = -1002432345513;
    
    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
         std::cout<<"message in message: "<<message->text<<"\n";
         
        answ_message = message->text;
        if ((answ_message.find(gen_message) != std::string::npos) && !m_map[gen_message]) {
            m_map[gen_message] = true;
        }
    });
    try {
        TgBot::TgLongPoll longPoll( *t_bot);
        while (!shutdown_requested) {
            printf("LONG POLL IS WORKING!\n");
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}










    //run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    // generatorThread.join()


    // auto checker_f = [&](){
    //     checker();
    // };

    // auto main_f = [&](){
    //     run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    // };

    //std::thread generatorThread{generator_f};

    //checker(); 
   // generator();


    //generator();


    //std::thread checkerThread{checker_f}; 

    //generatorThread.join();   
    //checker(); 
    //checker();
    //std::thread generatorThread{generator_f};
    //generatorThread.join();
;
    //std::thread checkerThread{checker_f}; 
    //checkerThread.join();
    //checker();
