cmake_minimum_required(VERSION 3.15)

project (CursedWordsTGBot CXX)

set(target CursedWordsTGBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_subdirectory(CursedWordsTGBot)
add_subdirectory(Modules)
add_subdirectory(Tests)


#set(TgBot_DIR "/home/ivan/tgbot-cpp/CMakeFiles/Export/lib/cmake/TgBot/")

message("QWERTY")
message(${TgBot_DIR})

find_package(TgBot)

#   if(TgBot_FOUND)
        #set(TgBot_LIBRARIES " ")
        #set(TgBot_include_DIRS " ")
#   else
    #message("DANAGER!")

#   endif()


target_include_directories( ${target} PUBLIC .)