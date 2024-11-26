set(target threadsafequeue_test)

add_executable(${target} test.cpp main.cpp)
target_include_directories(${target} PUBLIC .)
target_link_libraries(${target} PRIVATE gtest task queue)

add_test(NAME threadsafequeue_test COMMAND ${target})