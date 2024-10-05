#pragma once

#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <string>

struct Task{
    std::string message;
    std::string chat_title;
    std::string firstName;
    std::string lastName;
    std::int64_t id_m;

    Task(std::string mss, std::string cht, std::string fN, std::string lN, std::int64_t id): message(mss), chat_title(cht),firstName(fN), lastName(lN),  id_m(id){

    }
    
    friend bool operator == (const Task& task1, const Task& task2){
        return task1.message == task2.message;
    }
};



