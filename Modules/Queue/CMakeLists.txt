set(target queue)

add_library(${target} STATIC queue.cpp)
target_include_directories(${target} INTERFACE .)
target_link_libraries( ${target}  task )