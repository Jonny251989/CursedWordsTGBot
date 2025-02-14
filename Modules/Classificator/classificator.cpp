#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){
    

}

    
std::string SimpleClassificator::check() {
    // Начало замера времени
    auto start_time = std::chrono::high_resolution_clock::now();

    // Формируем команду для запуска Python-скрипта
    std::string command = "python3 ./Modules/Classificator/classifier.py \"" + message_ + "\"";

    // Открываем процесс и захватываем его вывод
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "Ошибка при запуске Python-скрипта.";
    }

    // Читаем вывод скрипта
    char buffer[128];
    std::string result;
    while (fgets(buffer, sizeof(buffer), pipe)) {
        result += buffer;
    }

    // Закрываем процесс
    int status = pclose(pipe);
    if (status != 0) {
        return "Ошибка при выполнении Python-скрипта.";
    }

    // Конец замера времени
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;  // Разница во времени

    // Выводим время работы
    std::cout << "ВРЕМЯ ВЫПОЛНЕНИЯ КЛАССИФИКАЦИИ: " << duration.count() << " секунд" << std::endl;

    try {
        double toxicity_prob = std::stod(result);  // Преобразуем строку в double

        if (toxicity_prob > 0.5) {
            return "Сообщение токсичное! Вероятность: " + std::to_string(toxicity_prob) + "\n";
        } else {
            return "Сообщение не токсичное. Вероятность: " + std::to_string(toxicity_prob) + "\n";
        }

    } catch (const std::invalid_argument& e) {
        return "Ошибка: не удалось преобразовать результат в число.";
    } catch (const std::out_of_range& e) {
        return "Ошибка: число выходит за пределы допустимого диапазона.";
    }
}

SimpleClassificator::~SimpleClassificator(){

}