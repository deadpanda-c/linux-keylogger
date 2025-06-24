cmake_minimum_required(VERSION 3.22)
project(linux-keylogger)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SOURCES src/*.cpp)
include_directories(include)

add_executable(${PROJECT_NAME} ${SOURCES})
