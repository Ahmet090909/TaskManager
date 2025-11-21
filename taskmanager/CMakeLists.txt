cmake_minimum_required(VERSION 3.16)
project(TaskManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TaskManager
    src/main.cpp
    src/Task.cpp
    src/SimpleTask.cpp
    src/TaskManager.cpp
    include/Task.h
    include/SimpleTask.h
    include/TaskManager.h
)

target_include_directories(TaskManager PRIVATE include)
