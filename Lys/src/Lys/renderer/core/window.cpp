#include "window.hpp"

#include "Lys/core/input/input_manager.hpp"
#include "Lys/core/input/keyboard.hpp"
#include "Lys/debug/logging.hpp"
#include "Lys/main/application.hpp"
#include "Lys/renderer/core/renderer.hpp"

namespace Lys
{
	bool Window::_glfwInitialized = false;
	bool Window::_isPolygonMode = false;

	void Window::frame_buffer_callback(GLFWwindow *window, const int width, const int height)
	{
		Renderer::get_singleton()->update_viewport(width, height);
	}

	Window::Window() : _width(0), _height(0), _window(nullptr) {}

	Window::Window(const int width, const int height) :
		_width(width), _height(height), _window(nullptr)
	{
	}

	Window::Window(const int width, const int height, const std::string &title) :
		_width(width), _height(height), _title(title), _window(nullptr)
	{
	}

	void Window::set_title(const std::string &title) { _title = title; }

	void Window::initialize()
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Creates the window to be displayed
		_window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
		if (_window == nullptr)
		{
			glfwTerminate();
			LYS_CRITICAL("Failed to initialize glfw.", glGetError());
		}

		// Makes the current window context
		glfwMakeContextCurrent(_window);
		_glfwInitialized = true;

		Renderer::get_singleton()->init();

		// Associates window user pointer with current instance
		glfwSetWindowUserPointer(_window, this);
		glfwSetFramebufferSizeCallback(_window, frame_buffer_callback);
		glfwSetKeyCallback(_window, InputManager::_process_input_callback);
		glfwSetCursorPosCallback(_window, InputManager::_process_mouse_callback);
		glfwSetInputMode(_window, GLFW_STICKY_KEYS, GLFW_FALSE);
		glfwMakeContextCurrent(_window);
		glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		frame_buffer_callback(_window, _width, _height);
	}

	bool Window::is_done() const
	{
		if (!_glfwInitialized)
		{
			return true;
		}

		return glfwWindowShouldClose(_window);
	}

	void Window::poll_events() { glfwPollEvents(); }

	void Window::close() const { glfwSetWindowShouldClose(_window, true); }

	void Window::force_close() { glfwDestroyWindow(_window); }

	void Window::swap_frame_buffer() { glfwSwapBuffers(_window); }

	void Window::terminate()
	{
		_glfwInitialized = false;
		glfwTerminate();
	}

	void Window::set_dimensions(const int width, const int height)
	{
		_width = width;
		_height = height;
	}

	GLFWwindow *Window::get_window() const { return _window; }

	Point2 Window::get_mouse_position()
	{
		// Gets the current active window
		GLFWwindow *window = Application::get_singleton()->get_window()->get_window();
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return {static_cast<float>(xpos), static_cast<float>(ypos)};
		return {0, 0};
	}
} // namespace Lys
