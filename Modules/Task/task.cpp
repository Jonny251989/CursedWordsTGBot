#include "task.hpp"

Task::Task(){

}

void Task::execute(){

}


Task::~Task(){

}



CursedWordDetectingTask::CursedWordDetectingTask(std::string mss, std::string cht, std::string fN, std::string lN, std::int64_t id): message(mss), chat_title(cht),firstName(fN), lastName(lN),  id_m(id){

}


void CursedWordDetectingTask::execute(){
    Logger::getInstance().logInfo(Logger::Levels::Info, message);
}


CursedWordDetectingTask::~CursedWordDetectingTask(){

}