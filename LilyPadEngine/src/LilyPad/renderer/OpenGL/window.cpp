#include "LilyPad/renderer/OpenGL/window.hpp"

#include "LilyPad/core/input/input.hpp"
#include "LilyPad/core/input/keyboard.hpp"
#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	void Window::frame_buffer_callback(GLFWwindow *window, const int width, const int height)
	{
		glViewport(0, 0, width, height);
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
			LILYPAD_CRITICAL("Failed to initialize glfw.", glGetError());
		}

		// Makes the current window context
		glfwMakeContextCurrent(window);

		// Initializes GLEW
		GLenum init = glewInit();
		if (init != GLEW_OK)
		{
			LILYPAD_CRITICAL("GLEW failed to initialize correctly.", glGetError());
		}

		// (x, y) coords of corner, (length, width) of window
		glViewport(0, 0, _width, _height);
		glfwSetFramebufferSizeCallback(window, frame_buffer_callback);

		LILYPAD_INFO("Renderer: ", glGetString(GL_RENDERER));
		LILYPAD_INFO("OpenGL version: ", glGetString(GL_VERSION));

		int numAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributes);
		LILYPAD_INFO("Maximum number of vertex attributes supported: ", numAttributes);

		// Associates window user pointer with current instance
		glfwSetWindowUserPointer(window, this);

		glfwSetFramebufferSizeCallback(window, frame_buffer_callback);

		// Sets key callback function
		glfwSetKeyCallback(window, process_input);
		glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
		glfwMakeContextCurrent(window);
	}

	bool Window::is_done() const { return glfwWindowShouldClose(window); }

	void Window::poll_events() { glfwPollEvents(); }

	void Window::close() { glfwSetWindowShouldClose(window, true); }

	void Window::swap_frame_buffer() { glfwSwapBuffers(window); }

	void Window::terminate() { glfwTerminate(); }

	void Window::set_dimensions(const int width, const int height)
	{
		_width = width;
		_height = height;
	}
} // namespace LilyPad