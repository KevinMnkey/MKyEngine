#include "window.hpp"
#include <iostream>

namespace core {

	Window::Window(int width, int height, const std::string& title)
		: m_width(width), m_height(height), m_title(title) {

		if (!glfwInit()) {
			std::cerr << "Error al inicializar GLFW";
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
		if (!m_window) {
			std::cerr << "Error al crear la ventana de GLFW\n";
			glfwTerminate();
		}
	}

	Window::~Window() {
		if (m_window) {
			glfwDestroyWindow(m_window);
		}
		glfwTerminate();
	}

	bool Window::should_close() const {
		return glfwWindowShouldClose(m_window);
	}
	void Window::poll_events() const {
		glfwPollEvents();
	}
}