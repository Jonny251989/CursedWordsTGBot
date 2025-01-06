#include "reactor.hpp"

EchoReactor::EchoReactor(std::shared_ptr<TgBot::Bot> ptr_bot, std::string message, std::int64_t chat_id, TgBot::User::Ptr from): 
ptr_bot_(ptr_bot), message_(message), chat_id_(chat_id), from_(from){

}

void EchoReactor::react(bool classification_result){
    ptr_bot_->getApi().sendMessage(chat_id_, "Your message is: " + message_ + " is good!\n");
    Logger::getInstance().logInfo(Logger::Levels::Info, ("Message " + message_ + " is good! \n"));
}

EchoReactor::~EchoReactor(){

}