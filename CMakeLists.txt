cmake_minimum_required(VERSION 4.0)
project(miniPokemon)

file(GLOB SRC_FILE src/*.cpp) #macro para armazenar todos os files .cpp dentro da pasta numa variável

add_executable(${PROJECT_NAME} ${SRC_FILE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


target_include_directories(${PROJECT_NAME} PUBLIC include/)