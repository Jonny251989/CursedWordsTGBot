cmake_minimum_required(VERSION 3.15)

project (CursedWordsTGBot CXX)

set(target CursedWordsTGBot)

set(Boost_USE_MULTITHREADED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include(cmake/TgBot.cmake)

enable_testing() 

find_package(TgBot REQUIRED)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

add_subdirectory(CursedWordsTGBot)
add_subdirectory(Modules)
add_subdirectory(Tests)

if (CURL_FOUND)
    target_include_directories( ${target} PUBLIC ${CURL_INCLUDE_DIRS} )
    target_compile_definitions(${target} PRIVATE -DHAVE_CURL )
endif()