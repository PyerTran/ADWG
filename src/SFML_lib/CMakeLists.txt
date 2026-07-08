cmake_minimum_required(VERSION 4.2.3)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 3.1.0
)
FetchContent_MakeAvailable(SFML)

add_library(MySFML ./src/MySfml.cpp ./src/components/sfml_specific.cpp)

add_dependencies(MySFML CORE)


target_include_directories(MySFML
    PUBLIC    
    ./include/)

target_include_directories(MySFML
    PUBLIC
    ./src/components/)

target_link_libraries(MySFML sfml-graphics sfml-system)