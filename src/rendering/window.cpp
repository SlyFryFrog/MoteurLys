#include "window.hpp"
#include "debug/logging.hpp"

namespace LilyPad
{
	Window::Window() {}

	Window::Window(int width, int height) : width(width), height(height) {}

	void Window::frame_buffer_callback(GLFWwindow *window, const int width, const int height)
	{
		glViewport(0, 0, width, height);
	}

	void Window::initiate() 
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Creates the window to be displayed
		pWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (pWindow == nullptr)
		{
			glfwTerminate();
			LILYPAD_CRITICAL("Failed to initialize glfw.", glGetError());
		}

		// Makes the current window context
		glfwMakeContextCurrent(pWindow);

		GLenum init = glewInit();
		if (init != GLEW_OK)
		{
			LILYPAD_CRITICAL("GLEW failed to initialize correctly.", glGetError());
		}

		// (x, y) coords of corner, (length, width) of window
		glViewport(0, 0, width, height);
		glfwSetFramebufferSizeCallback(pWindow, frame_buffer_callback);

		// Print out the OpenGL version we are using
		LILYPAD_INFO("OpenGL version: ", glGetString(GL_VERSION));

		int numAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributes);
		LILYPAD_INFO("Maximum number of vertex attributes supported: ", numAttributes);

		// Associates window user pointer with current pWindow
		glfwSetWindowUserPointer(pWindow, this);
	}

	void Window::set_title(const std::string &title) { this->title = title; }

	void Window::set_dimensions(int width, int height)
	{
		this->width = width;
		this->height = height;
	}
} // namespace LilyPad