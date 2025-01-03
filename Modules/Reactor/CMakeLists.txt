set(target reactor)

add_library(${target} STATIC reactor.cpp)

target_include_directories( ${target} PUBLIC . )

target_link_libraries(${target} PUBLIC logger task)