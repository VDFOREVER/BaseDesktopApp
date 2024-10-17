cmake_minimum_required(VERSION 3.10)

project(example)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ${SRC_FILES})
include_directories(include)
target_link_libraries(${PROJECT_NAME} gui)