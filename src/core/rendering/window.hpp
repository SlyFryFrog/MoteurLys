#pragma once

#include <GL/glew.h> // Needs to be included before GLFW
#include <GLFW/glfw3.h>
#include <string>

namespace LilyPad
{
	/**
	 * @brief Main window for rendering.
	 */
	class Window
	{
	private:
		bool isPolygonMode; // Boolean to either enable or disable polygon rendering
		int width;			// Window width
		int height;			// Window height
		std::string title;

		/**
		 * @brief
		 *
		 * @param window
		 * @param width
		 * @param height
		 */
		static void frame_buffer_callback(GLFWwindow *window, int width, int height);

		/**
		 * @brief
		 *
		 * @param window
		 * @param key
		 * @param scancode
		 * @param action
		 * @param mods
		 */
		static void process_input(GLFWwindow *window, int key, int scancode, int action, int mods);

	public:
		GLFWwindow *window;

		/**
		 * @brief Construct a new Window object with all variables set to nullptr.
		 */
		Window();

		/**
		 * @brief Construct a new Window object.
		 *
		 * @param width Width of the window.
		 * @param height Height of the window.
		 */
		Window(const int width, const int height);

		/**
		 * @brief Construct a new Window object.
		 *
		 * @param width Width of the window.
		 * @param height Height of the window.
		 * @param title Title of the window.
		 */
		Window(const int width, const int height, const std::string &title);

		/**
		 * @brief Set the title of the window.
		 *
		 * @param title New title.
		 */
		void set_title(const std::string &title);

		/**
		 * @brief Sets up GLFW, creates a window, sets OpenGL context parameters, initializes GLEW, sets viewport, and
		 * registers callback functions.
		 *
		 * @throws WindowInitializationError if GLFW window creation or GLEW initialization fails.
		 */
		void initialize();

		/**
		 * @brief Returns the boolean status indicating whether the glfw window is ready to close or not.
		 *
		 * @return true glfwWindowShouldClose and is done.
		 * @return false glfwWindowShouldClose is false and not done.
		 */
		[[nodiscard]] bool is_done() const;

		void set_dimensions(int width, int height);
	};
} // namespace LilyPad