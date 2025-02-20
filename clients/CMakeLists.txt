cmake_minimum_required(VERSION 3.14)
project(client)

set(target client)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/protobuf")
set(Protobuf_PROTOC_EXECUTABLE /usr/local/bin/protoc)

find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)
find_package(utf8_range REQUIRED)
find_package(absl REQUIRED)

set(PROTO_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/toxicity_classifier.pb.cc)
set(PROTO_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/toxicity_classifier.pb.h)
set(GRPC_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/toxicity_classifier.grpc.pb.cc)
set(GRPC_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/toxicity_classifier.grpc.pb.h)
set(PYTHON_SCRIPT_PATH /home/ivan/git_projects/CursedWordsTGBot/server_grpc/server.py)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(${target} STATIC client.cpp ${PROTO_SRCS} ${GRPC_SRCS})
    
target_include_directories(${target} PUBLIC . ${PROTO_HDRS} ${GRPC_HDRS})

target_link_libraries(${target}
    PUBLIC
    absl::check
    absl::cord
    absl::cord_internal 
    absl::strings  
    ${ABSL_LIBRARIES}
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
    gRPC::grpc++
    gRPC::grpc++_reflection
    ${Protobuf_LIBRARIES}
    utf8_range::utf8_validity
)
