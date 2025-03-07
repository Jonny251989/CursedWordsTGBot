#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){
    
       ptr_client_ = std::make_unique<ToxicityClassifierClient>(grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials()));
}

std::string SimpleClassificator::check() {

    auto start_time = std::chrono::high_resolution_clock::now();

    float probability = ptr_client_->ClassifyMessage(message_);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    // std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    // std::cout << "Message: " << message_ << " Toxicity Probability: " << probability << std::endl;
    if(probability > 0.5) return "мат!"; 
    else return "не мат";
}



SimpleClassificator::~SimpleClassificator(){

}