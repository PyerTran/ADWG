cmake_minimum_required(VERSION 4.2.3)

add_library(CORE ./utils/angle.cpp)

target_include_directories(CORE
    PUBLIC
    ./module)

target_include_directories(CORE
    PUBLIC
    ./module/ecs)

target_include_directories(CORE
    PUBLIC
    ./system)
target_include_directories(CORE
    PUBLIC
    ./utils)