#include "core/window.hpp"
#include "renderer/vulkan_context.hpp"
#include <iostream>
#include <windows.h>

int main() {
    // 1. Crear la ventana
    core::Window window(800, 600, "MNKY_Engine");

    // 2. Inicializar Vulkan
    renderer::VulkanContext vulkanContext;
    vulkanContext.init(window.get_native_handle());

    // 3. Bucle del juego
    while (!window.should_close()) {
        window.poll_events();
    }

    // Al salir del scope, los destructores de `vulkanContext` y `window` 
    // liberan la memoria automáticamente en el orden correcto.
    return 0;
}