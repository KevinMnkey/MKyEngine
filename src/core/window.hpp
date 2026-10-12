#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace core {

	class Window {
	public:
		Window(int width, int height, const std::string& title);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		bool should_close() const;
		void poll_events() const;

		GLFWwindow* get_native_handle() const { return m_window; }

	private:
		GLFWwindow* m_window = nullptr;
		int m_width;
		int m_height;
		std::string m_title;
	};


}