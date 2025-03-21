#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){
    
    const char* server_address = std::getenv("GRPC_SERVER_ADDRESS");
    if (!server_address) {
        server_address = "127.0.0.1:50051"; // Значение по умолчанию
    }
    ptr_client_ = std::make_unique<ToxicityClassifierClient>(
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
}

std::string SimpleClassificator::check() {

    auto start_time = std::chrono::high_resolution_clock::now();

    float probability = ptr_client_->ClassifyMessage(message_);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    if(probability > 0.5) return "мат!"; 
    else return "не мат";
}



SimpleClassificator::~SimpleClassificator(){

}