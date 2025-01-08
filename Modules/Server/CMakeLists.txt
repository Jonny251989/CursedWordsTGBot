
set(target server_bot)

set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

add_library(${target} STATIC server.cpp)

target_include_directories( ${target} PUBLIC . ${TgBot_include_DIR} ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR} ${GTEST_INCLUDE_DIRS})

if (CURL_FOUND)
    target_include_directories( ${target} PUBLIC ${CURL_INCLUDE_DIRS} )
    target_compile_definitions(${target} PRIVATE -DHAVE_CURL )
endif()


message(STATUS "TgBot_LIBRARIES: ${TgBot_LIBRARIES}")
message(STATUS "CMAKE_THREAD_LIBS_INIT: ${CMAKE_THREAD_LIBS_INIT}")
message(STATUS "OPENSSL_LIBRARIES: ${OPENSSL_LIBRARIES}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "CURL_LIBRARIES: ${CURL_LIBRARIES}")

target_link_libraries( ${target} ${TgBot_LIBRARIES}/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} queue task logger classificator reactor)

set_target_properties(server_bot PROPERTIES LINKER_LANGUAGE CXX)