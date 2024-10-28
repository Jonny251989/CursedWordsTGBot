set(target queue_test)

add_executable(${target} test.cpp main.cpp)
target_include_directories(${target} PUBLIC .)
target_link_libraries(${target} PRIVATE gtest queue task)

add_test(NAME queue_test COMMAND ${target})