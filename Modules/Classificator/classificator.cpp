#include "classificator.hpp"

SimpleClassificator::SimpleClassificator(const std::string& message): message_(message){
    

}

std::string SimpleClassificator::check() {
    auto start_time = std::chrono::high_resolution_clock::now();

    PyRun_SimpleString("import sys; sys.path.append('/home/ivan/git_projects/CursedWordsTGBot/Modules/Classificator')");
    PyObject* pName = PyUnicode_DecodeFSDefault("classifier");
    PyObject* pModule = PyImport_Import(pName);
    Py_XDECREF(pName);

    if (pModule == nullptr) {
        PyErr_Print();
        Py_Finalize();
        return "Ошибка при импорте Python-скрипта.";
    }

    PyObject* pFunc = PyObject_GetAttrString(pModule, "classify_message");
    if (pFunc == nullptr || !PyCallable_Check(pFunc)) {
        PyErr_Print();
        Py_XDECREF(pModule);
        Py_Finalize();
        return "Ошибка при получении функции classify_message.";
    }

    PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString(message_.c_str()));
    if (pArgs == nullptr) {
        Py_XDECREF(pFunc);
        Py_XDECREF(pModule);
        Py_Finalize();
        return "Ошибка при упаковке аргумента.";
    }

    PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
    Py_XDECREF(pArgs);
    Py_XDECREF(pFunc);
    Py_XDECREF(pModule);

    if (pValue == nullptr) {
        PyErr_Print();
        Py_Finalize();
        return "Ошибка при вызове Python-функции.";
    }

    double toxicity_prob = 0.0;
    if (PyObject_TypeCheck(pValue, &PyFloat_Type)) {
        toxicity_prob = PyFloat_AsDouble(pValue);
    } else if (PyArray_IsScalar(pValue, Float32)) {
        toxicity_prob = PyFloat_AsDouble(pValue);  
    } else {
        PyErr_Print();
        Py_XDECREF(pValue);
        Py_Finalize();
        return "Ошибка: возвращаемое значение не является числом.";
    }

    Py_XDECREF(pValue);

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Время выполнения классификации: " << duration.count() << " секунд" << std::endl;

    if (toxicity_prob > 0.5) {
        Py_Finalize();
        return "Сообщение токсичное! Вероятность: " + std::to_string(toxicity_prob) + "\n";
    } else {
        Py_Finalize();
        return "Сообщение не токсичное. Вероятность: " + std::to_string(toxicity_prob) + "\n";
    }
}



SimpleClassificator::~SimpleClassificator(){

}