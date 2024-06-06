#pragma once

#include <GL/glew.h> // Needs to be included before GLFW
#include <GLFW/glfw3.h>
#include <string>

namespace LilyPad
{
	class Window
	{
	private:
		int width;
		int height;
		std::string title;
		GLFWwindow *pWindow;
	public:
		Window();
		Window(int width, int height);

		void frame_buffer_callback(GLFWwindow *window, const int width, const int height);
        void initiate();
		void set_title(const std::string &title);
		void set_dimensions(int width, int height);
	};
} // namespace LilyPad