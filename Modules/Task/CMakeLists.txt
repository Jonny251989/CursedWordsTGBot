set (target task)

add_library(${target} STATIC task.cpp)
target_include_directories(${target} PUBLIC .)