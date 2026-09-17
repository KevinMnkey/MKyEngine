cmake_minimum_required(VERSION 3.20)
project(Engine3D CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Descarga automática de GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

# Ejecutable principal
add_executable(Engine3D src/main.cpp)

# Enlazamos GLFW y la librería nativa de OpenGL de Windows (opengl32)
target_link_libraries(Engine3D PRIVATE glfw opengl32)