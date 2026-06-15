cmake_minimum_required(VERSION 3.15)
project(Brasilmon)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
)
FetchContent_MakeAvailable(raylib)
# ----------------------------------------------------------------

# Todos os seus arquivos .cpp do jogo
add_executable(Brasilmon
    src/acoes.cpp
    src/graphs.cpp
    src/personagens.cpp
    src/pokedex.cpp
    src/main.cpp
)

# Conecta a raylib ao seu projeto
target_link_libraries(Brasilmon PRIVATE raylib)

# Mostra onde estão os SEUS arquivos .hpp
target_include_directories(Brasilmon PRIVATE
    include
)

# Copy assets to build directory (Descomente tirando o '#' se você tiver uma pasta assets)
# file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})