set (target task)

add_library(${target} INTERFACE)
target_include_directories(${target} INTERFACE .)

set_target_properties(task PROPERTIES LINKER_LANGUAGE CXX)
