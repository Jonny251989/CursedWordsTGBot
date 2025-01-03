#include "task.hpp"

CRTask::CRTask(std::shared_ptr<IClassificator> classificator, std::shared_ptr<IReactor> reactor): classificator_(classificator), reactor_(reactor){

}

void CRTask::execute(){

}

CRTask::~CRTask(){

}


CursedWordDetectingTask::CursedWordDetectingTask(std::shared_ptr<IClassificator> classificator, std::shared_ptr<IReactor> reactor, std::string mss, std::string cht, std::string fN, std::string lN, std::int64_t id)
: CRTask(classificator, reactor), message(mss), chat_title(cht),firstName(fN), lastName(lN),  id_m(id){

}

void CursedWordDetectingTask::execute(){
    if(this->classificator_->check(*this))
        Logger::getInstance().logInfo(Logger::Levels::Info, ("Message " + this->reactor_->send_message() + " is good! \n"));
    else
        Logger::getInstance().logInfo(Logger::Levels::Info, ("Message " + this->reactor_->send_message() + " is terrible! \n"));
    
}

CursedWordDetectingTask::~CursedWordDetectingTask(){

}