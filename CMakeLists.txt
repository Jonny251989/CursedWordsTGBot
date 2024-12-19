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

# TgBot_LIBRARIES TgBot_include_DIRS

# message("QWERTY")
# message(${TgBot_DIR})

#set(BASE_PATH "/home/runner/work/CursedWordsTGBot/CursedWordsTGBot/tgbot-cpp")
set(TgBot_DIR "${BASE_PATH}/lib/cmake/TgBot/")
set(TgBot_include_DIR "${BASE_PATH}/include/")
set(TgBot_LIBRARIES "${BASE_PATH}/lib/")


find_package(TgBot)

message("FILE LOCATION IS ")
if(DEFINED BASE_PATH)
    message("BASE_PATH is defined as: ${BASE_PATH}")
    message("TgBot_DIR is defined as: ${TgBot_DIR}")
    message("TgBot_include_DIR is defined as: ${TgBot_include_DIR}")
    message("TgBot_LIBRARIES is defined as: ${TgBot_LIBRARIES}")
else()
    message("BASE_PATH is not defined!")
endif()



#   if(TgBot_FOUND)
#     # set(TgBot_DIR "${BASE_PATH}/lib/cmake/TgBot")
#     # set(TgBot_include_DIR "${BASE_PATH}/include")
#     # set(TgBot_LIBRARIES "${BASE_PATH}/CMakeFiles/Export/lib")
#   else()
#     message("DANAGER!")

#   endif()

target_include_directories( ${target} PUBLIC .)