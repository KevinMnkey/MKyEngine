#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Error al inicializar GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Motor 3D - Fase 1", NULL, NULL);
    if (!window) {
        std::cerr << "Error al crear la ventana\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Game Loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.1f, 0.1f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}