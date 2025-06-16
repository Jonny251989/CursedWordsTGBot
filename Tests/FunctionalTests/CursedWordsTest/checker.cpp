#include "checker.hpp"

void Checker::TearDown() {

}

void Checker::SetUp() {
    std::string token = "7913850529:AAHRcgeMjun-7U0mWsh5TF2NPUE8WyLGkLU";
    t_bot = std::make_shared<TgBot::Bot>(token);
    count_recieve_messages = 0;
    chat_id_ = -1002432345513;
}

void Checker::fill_map(){
    
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

        message_container[line] = flag;

    }
    inputFile.close();
}

void Checker::checker(){
    auto last_change_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = std::chrono::duration<double>::zero();

    t_bot->getEvents().onAnyMessage([&](TgBot::Message::Ptr message) {
            count_recieve_messages++;

            std::lock_guard lg{set_mutex};
            if(message->replyToMessage && message_container.count(message->replyToMessage->text)){
                bool react_m;
                message->text == "мат" ? react_m = true : react_m = false;
                std::cout<< "message->text: "<<message->text<<", react_m: "<<react_m<<"\n";
                ASSERT_EQ(message_container[message->replyToMessage->text], react_m);
            }

            last_change_time = std::chrono::steady_clock::now(); 
    });
    try {
        TgBot::TgLongPoll longPoll( *t_bot);
        while (count_recieve_messages <= limit_sent_messages_ && elapsed_seconds.count() < limit_time_in_sec) {
            longPoll.start();
            elapsed_seconds = std::chrono::steady_clock::now() - last_change_time;
        }
    } catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }
}

TEST_F(Checker, FirstTest) {
 

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::raise(SIGINT);
    
    checker();

}