#include "window.hpp"

#include "Lys/core/input/input.hpp"
#include "Lys/core/input/keyboard.hpp"
#include "Lys/debug/logging.hpp"

namespace Lys
{
	#ifdef OpenGL
	RendererGL Window::renderer;
	#endif
	
	void Window::frame_buffer_callback(GLFWwindow *window, const int width, const int height)
	{
		renderer.update_viewport(width, height);
	}

	void Window::process_input(GLFWwindow *window, const int key, const int scancode, const int action, const int mods)
	{
		const auto *windowInstance = static_cast<Window *>(glfwGetWindowUserPointer(window));
		Input *inputs = Input::get_singleton();
		Key keyCode = convert_code(key);
		auto position = KeyPosition::UNKNOWN;
		bool isRegistered = false;

		for (auto &event : inputs->get_keys_events())
		{
			if (keyCode != event.get_key())
				continue;
			isRegistered = true;
		}

		if (!isRegistered)
		{
			inputs->add_key_event(keyCode);
		}
		else
		{
			if (action == GLFW_RELEASE)
			{
				inputs->get_event(keyCode)->set_pressed(false);
				inputs->get_event(keyCode)->set_repeat(false);
			}
		}
	}

	Window::Window() : _isPolygonMode(false), _width(0), _height(0), window(nullptr) {}

	Window::Window(const int width, const int height) :
		_isPolygonMode(false), _width(width), _height(height), window(nullptr)
	{
	}

	Window::Window(const int width, const int height, const std::string &title) :
		_isPolygonMode(false), _width(width), _height(height), _title(title), window(nullptr)
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
		window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
		if (window == nullptr)
		{
			glfwTerminate();
			LYS_CRITICAL("Failed to initialize glfw.", glGetError());
		}

		// Makes the current window context
		glfwMakeContextCurrent(window);

		renderer.init();

		// Associates window user pointer with current instance
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, frame_buffer_callback);
		glfwSetKeyCallback(window, process_input);
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, frame_buffer_callback);

		frame_buffer_callback(window, _width, _height);
	}

	bool Window::is_done() const { return glfwWindowShouldClose(window); }

	void Window::poll_events() { glfwPollEvents(); }

	void Window::close() { glfwSetWindowShouldClose(window, true); }

	void Window::force_close() { glfwDestroyWindow(window); }

	void Window::swap_frame_buffer() { glfwSwapBuffers(window); }

	void Window::terminate() { glfwTerminate(); }

	void Window::set_dimensions(const int width, const int height)
	{
		_width = width;
		_height = height;
	}
} // namespace Lys