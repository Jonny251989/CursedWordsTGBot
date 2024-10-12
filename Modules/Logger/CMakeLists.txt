set(target logger)

add_library(${target} logger.cpp)
target_include_directories(${target} PUBLIC .)

