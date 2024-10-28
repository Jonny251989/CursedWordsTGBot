set(target queue)

add_library(${target} INTERFACE queue.hpp)
target_include_directories(${target} INTERFACE .)
target_link_libraries( ${target})