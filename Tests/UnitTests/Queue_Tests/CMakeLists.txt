set(target queue_tests)

add_executable(${target} onethreaded_test.cpp multithreaded_tests.cpp main.cpp)
target_include_directories(${target} PUBLIC .)
target_link_libraries(${target} PRIVATE gtest queue task)

add_test(NAME queue_test COMMAND ${target})