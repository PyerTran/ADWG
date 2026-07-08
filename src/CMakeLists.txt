cmake_minimum_required(VERSION 4.2.3)

project(Air_Defence_WARGAME)

add_subdirectory(core) #CORE
add_subdirectory(SFML_lib) #MySFML

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} CORE MySFML)