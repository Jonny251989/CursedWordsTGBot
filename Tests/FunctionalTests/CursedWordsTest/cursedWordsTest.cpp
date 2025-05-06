#include "cursedWordsTest.hpp"

void ReactorResultTest::TearDown() {

}

void ReactorResultTest::SetUp() {
    std::string token = "7212434431:AAFLuR1mQTqpageO7x575hkQzW7DzJTXdNs";
    t_bot = std::make_shared<TgBot::Bot>(token);
    if(t_bot){
        std::cout<<"WORKED\n";
    }
    else
        std::cout<<"NOT WORKED!\n";
    count_recieve_messages = 0;
    chat_id_ = -1002432345513;
}

void ReactorResultTest::generator(){
    
    const char* filePath = std::getenv("MESSAGES_FILE_PATH");
    if (!filePath) {
        filePath = "./Tests/FunctionalTests/CursedWordsTest/messages.txt";  // По умолчанию для локальной машины
    }
    std::ifstream inputFile(filePath);
    
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t last_space = line.find_last_of(' ');
        if (last_space == std::string::npos) {
            std::cerr << "Некорректный формат строки: " << line << std::endl;
            continue;
        }
        std::string flag_str = line.substr(last_space + 1);
        bool flag = (flag_str == "1");
        {
            std::lock_guard lg{set_mutex};
            message_container[line] = flag;
        }
        t_bot->getApi().sendMessage(chat_id_, line);
    }
    inputFile.close();
}

void ReactorResultTest::checker(){
    auto last_change_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>::zero();

    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {

            std::lock_guard lg{set_mutex};
            if(message->replyToMessage && message_container.count(message->replyToMessage->text)){
                bool react_m;
                count_recieve_messages++;
                if (message->text == "мат!") 
                    react_m = true;
                else
                    react_m = false;
                last_change_time = std::chrono::steady_clock::now();
                ASSERT_EQ(message_container[message->replyToMessage->text], react_m);
            }
    });
    try {
        TgBot::TgLongPoll longPoll( *t_bot);
        while (count_recieve_messages < limit_sent_messages_ && elapsed_seconds.count() < limit_time_in_sec) {
            longPoll.start();
            elapsed_seconds = std::chrono::steady_clock::now() - last_change_time;
            std::cout<<"elapsed AFTER 1: "<<elapsed_seconds.count()<<"\n";
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

TEST_F(ReactorResultTest, FirstTest) {

    std::jthread mainThread{[&](){
        run_bot("7763682966:AAEFBGifblSqB5of8cyS5WKjC6kK6pxTIuY");
    }};    

    generator();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    checker();

    std::raise(SIGINT);

}