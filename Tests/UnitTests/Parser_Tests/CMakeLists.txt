set(target parser_tests)

add_executable(${target} test.cpp main.cpp)
target_include_directories(${target} PUBLIC .)
target_link_libraries(${target} PRIVATE gtest parser)

add_test(NAME parser_tests COMMAND ${target})