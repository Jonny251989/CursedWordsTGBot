#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){
    
    pybind11::module_ sys = pybind11::module_::import("sys");
    sys.attr("path").attr("append")("./Modules/Classificator/");

    try {
        script_ = pybind11::module_::import("classifier");
    } catch (const pybind11::error_already_set& e) {
        std::cerr << "Ошибка при импорте модуля: " << e.what() << std::endl;
    }

}

    
std::string SimpleClassificator::check() {
   
    pybind11::object result;

    try {
        std::cout<<"check()\n";
        result = script_.attr("classify_message")(message_);
    } catch (const pybind11::error_already_set& e) {
        std::cerr << "Ошибка при вызове функции: " << e.what() << std::endl;
        return "Ошибка при вызове функции.";
    }

    double toxicity_prob = result.cast<double>();

    if (toxicity_prob > 0.5) {
        return "Вероятность, что сообщение матное -  " + std::to_string(toxicity_prob);
    } else {
        return "Вероятность, что сообщение не матное -  " + std::to_string(toxicity_prob);
    }
}

SimpleClassificator::~SimpleClassificator(){

}