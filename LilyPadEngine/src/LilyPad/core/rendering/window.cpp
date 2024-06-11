#include "LilyPad/core/rendering/window.hpp"

#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	void Window::frame_buffer_callback(GLFWwindow *window, const int width, const int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::process_input(GLFWwindow *window, const int key, const int scancode, const int action, const int mods)
	{
		auto *windowInstance = static_cast<Window *>(glfwGetWindowUserPointer(window));

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
		else if (key == GLFW_KEY_F3 && action == GLFW_PRESS)
		{
			// Changes how models are rendered
			windowInstance->_isPolygonMode = !windowInstance->_isPolygonMode;
			if (windowInstance->_isPolygonMode)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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

		// Print out the OpenGL version we are using
		LILYPAD_INFO("OpenGL version: ", glGetString(GL_VERSION));

		int numAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributes);
		LILYPAD_INFO("Maximum number of vertex attributes supported: ", numAttributes);

		// Associates window user pointer with current instance
		glfwSetWindowUserPointer(window, this);

		glfwSetFramebufferSizeCallback(window, frame_buffer_callback);

		// Sets key callback function
		glfwSetKeyCallback(window, process_input);
	}

	bool Window::is_done() const { return glfwWindowShouldClose(window); }

	void Window::set_dimensions(int width, int height)
	{
		_width = width;
		_height = height;
	}
} // namespace LilyPad