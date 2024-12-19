
set(target server_bot)

set(Boost_USE_MULTITHREADED ON)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)

add_library(${target} SHARED server.cpp)
#/usr/local/lib/libTgBot.a
target_include_directories( ${target} PUBLIC . ${TgBot_include_DIR} ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR} ${GTEST_INCLUDE_DIRS})

if (CURL_FOUND)
    target_include_directories( ${target} PUBLIC ${CURL_INCLUDE_DIRS} )
    target_compile_definitions(${target} PRIVATE -DHAVE_CURL )
endif()


target_link_libraries( ${target}  ${TgBot_LIBRARIES}/libTgBot.a ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES} queue task logger)

message("HERE HERE HERE HERE HERE!")

message("BASE_PATH is defined as: ${BASE_PATH}")
message("TgBot_DIR is defined as: ${TgBot_DIR}")
message("TgBot_include_DIR is defined as: ${TgBot_include_DIR}")
message("TgBot_LIBRARIES is defined as: ${TgBot_LIBRARIES}")

message(STATUS "INCLUDE_DIRECTORIES: ${dirs}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")

# if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR})
#     get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#     message(STATUS "INCLUDE_DIRECTORIES: ${dirs}")
#     foreach(dir ${dirs})
#         message(STATUS "dir='${dir}'")
#     endforeach()
# else()
#     message(STATUS "Directory ${CMAKE_CURRENT_SOURCE_DIR} does not exist!")
# endif()

get_target_property(includedirs ${target} INCLUDE_DIRECTORIES)
message(STATUS "INCLUDE_DIRECTORIES for ${target}: ${includedirs}")
foreach(dir ${includedirs})
    message(STATUS "dir='${dir}'")
endforeach()

set_target_properties(server_bot PROPERTIES LINKER_LANGUAGE CXX)