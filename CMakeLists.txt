cmake_minimum_required(VERSION 3.1)

project (MultiThread)

add_definitions("-Wall -Wextra -ggdb")
# add_subdirectory(logIf)

add_executable(MultiThread main.cpp)
# target_link_libraries(MultiThread PUBLIC logInterface)
target_link_libraries(MultiThread PUBLIC librt.so)
target_link_libraries(MultiThread PUBLIC libpthread.so)
# target_include_directories(MultiThread PUBLIC "logIf/interface/include")