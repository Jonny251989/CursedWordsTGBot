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
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
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
    //kill(getpid(), SIGTERM);
}

TEST_F(ReactorResultTest, FirstTest) {
    auto generator_f = [&](){
        generator();
    };
    // auto checker_f = [&](){
    //     checker();
    // };
    auto main_f = [&](){
        run_bot("7229787403:AAH0DVCx0wUQ-G9lkXYoIllHL0DhmdawEZo");
    };
    std::thread mainThread{main_f};
    std::thread generatorThread{generator_f};     
    checker();
    kill(getpid(), SIGINT);
    for(auto it = m_map.begin(); it != m_map.end(); it++){
        std::cout<<"key: "<<it->first<<", value: "<<it->second<<"\n";
    }
    generatorThread.join();
    mainThread.join();
}

void ReactorResultTest::checker(){
    chat_id = -1002432345513;
    auto last_change_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>::zero();

    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
        // message->messageId;
        // message->replyToMessage->text;
        if(message->replyToMessage !=nullptr)
            std::cout<<"replyToMessage: "<<message->replyToMessage->text<<",\n";
            
        //elapsed_seconds = std::chrono::duration<double>::zero();
        last_change_time = std::chrono::steady_clock::now();
        //now = std::chrono::steady_clock::now();
        answ_message = message->text;
        if ((answ_message.find(gen_message) != std::string::npos) && !m_map[gen_message]) {
            m_map[gen_message] = true;
        }

        
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
