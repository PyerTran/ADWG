cmake_minimum_required(VERSION 4.2.3)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB all_COMPONENTS
    "./src/components/*.cpp"
    )

add_library(ADWG ./src/ADWG.cpp ${all_COMPONENTS})

target_include_directories(ADWG
    PUBLIC
    ./src)

target_include_directories(ADWG
    PUBLIC
    ./include/components)

add_dependencies(CORE)

target_link_libraries(ADWG CORE)