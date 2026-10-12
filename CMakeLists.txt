cmake_minimum_required(VERSION 3.20)
project(Engine3D CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Exporta las rutas de compilación para que el LSP / IDE encuentre los includes
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(DEFINED ENV{VULKAN_SDK})
    list(APPEND CMAKE_PREFIX_PATH "$ENV{VULKAN_SDK}")
endif()

# 1. Buscar el SDK de Vulkan
find_package(Vulkan REQUIRED)

# 2. Descarga automática de GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

# 3. Ejecutable principal
add_executable(Engine3D 
    src/main.cpp 
    src/core/window.cpp 
    src/renderer/vulkan_context.cpp
)

# 4. Cabeceras explícitas de Vulkan
target_include_directories(Engine3D PRIVATE ${Vulkan_INCLUDE_DIRS})

# 5. Enlazamos GLFW y Vulkan
target_link_libraries(Engine3D PRIVATE 
    glfw 
    Vulkan::Vulkan
)