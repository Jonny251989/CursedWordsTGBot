cmake_minimum_required(VERSION 3.15)

project (CursedWordsTGBot CXX)

set(target CursedWordsTGBot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(cmake/TgBot.cmake)

add_subdirectory(CursedWordsTGBot)
add_subdirectory(Modules)
add_subdirectory(Tests)

find_package(TgBot REQUIRED)

target_include_directories(${target} PUBLIC . ${TgBot_include_DIR})