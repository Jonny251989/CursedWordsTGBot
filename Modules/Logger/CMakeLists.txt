set(target logger)

add_library(${target} SHARED logger.cpp)
target_include_directories(${target} PUBLIC .)

