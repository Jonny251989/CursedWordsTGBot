set(target CursedWordsTGBot)

list(APPEND CMAKE_PREFIX_PATH "/home/ivan/tgbot-cpp/")

find_package(TgBot)

add_executable(${target} main.cpp)

target_include_directories( ${target} PUBLIC . /home/ivan/tgbot-cpp/include/tgbot/)

target_link_libraries(${target} PUBLIC server_bot logger parser worker queue signalhandler)