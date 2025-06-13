#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){

}

bool SimpleClassificator::check(){
    return true;
}

SimpleClassificator::~SimpleClassificator(){

}

CursedWordsClassificator::CursedWordsClassificator(const std::string& message): message_(message){
    
    const char* server_address = std::getenv("GRPC_SERVER_ADDRESS");
    if (!server_address) {
        server_address = "localhost:50051";
    }
    ptr_client_ = std::make_unique<ToxicityClassifierClient>(
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
}

bool CursedWordsClassificator::check() {
    float probability = ptr_client_->ClassifyMessage(message_);
    if(probability > 0.5) return true; 
    else return false;
}

CursedWordsClassificator::~CursedWordsClassificator(){ }