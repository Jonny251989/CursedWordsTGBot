set(target reactor_tests)

add_executable(${target} test_reactorsresult.cpp main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/CursedWordsTGBot)
target_include_directories(${target} PUBLIC .)
target_link_libraries(${target} PUBLIC gtest queue server_bot task parser worker signalhandler )

add_test(NAME queue_test COMMAND ${target})