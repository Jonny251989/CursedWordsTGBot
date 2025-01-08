#include "reactor.hpp"

EchoReactor::EchoReactor(std::shared_ptr<TgBot::Bot> ptr_bot, std::string message, std::int64_t chat_id, TgBot::User::Ptr from): 
ptr_bot_(ptr_bot), message_(message), chat_id_(chat_id), from_(from){

}

void EchoReactor::react(bool classification_result){
    ptr_bot_->getApi().sendMessage(chat_id_, "Reactor got message: " + message_ + ". It is cursing and we don't swear!\n");
    Logger::getInstance().logInfo(Logger::Levels::Info, ("Reactor got message: " + message_ + ". It is cursing and we don't swear!\n"));
}

EchoReactor::~EchoReactor(){

}