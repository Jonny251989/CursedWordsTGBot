set(target worker)

add_library(${target} SHARED worker.cpp)

target_include_directories( ${target} PUBLIC . )

target_link_libraries(${target} PUBLIC logger queue task)