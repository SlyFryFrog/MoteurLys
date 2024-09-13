#pragma once

#ifdef OPENGL
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <string>
#include "Lys/core/math/vector2.hpp"

namespace Lys
{
	/**
	 * @brief Main window for rendering.
	 */
	class Window
	{
		GLFWwindow *_window;
		static bool _glfwInitialized;

	public:
		Window();

		/**
		 * @brief Construct a new Window object.
		 *
		 * @param width Width of the window.
		 * @param height Height of the window.
		 */
		Window(int width, int height);

		/**
		 * @brief Construct a new Window object.
		 *
		 * @param width Width of the window.
		 * @param height Height of the window.
		 * @param title Title of the window.
		 */
		Window(int width, int height, const std::string &title);

		/**
		 * @brief Set the title of the window.
		 *
		 * @param title New title.
		 */
		void set_title(const std::string &title);

		/**
		 * @brief Sets up GLFW, creates a window, sets OpenGL context parameters, initializes GLEW, sets viewport, and
		 * registers callback functions.
		 */
		void initialize();

		/**
		 * @brief Returns the status of the window's completion status.
		 *
		 * @return true		GLFW window is done and should be closed.
		 * @return false 	GLFW window is not done and should not be closed.
		 */
		[[nodiscard]] bool is_done() const;

		/**
		 * @brief Sets the width and height of the window instance.
		 *
		 * @param width New window width.
		 * @param height New window height.
		 */
		void set_dimensions(int width, int height);

		void poll_events();

		/**
		 * @brief Closes the window instance while not terminating the underlying library.
		 */
		void close() const;

		/**
		 * @brief Closes the window and its context without calling any registered callbacks.
		 *
		 * @note Since this destroys the window without any callbacks, this should only be done on the main thread.
		 */
		void force_close();

		/**
		 * @brief Swaps the front and back frame buffers.
		 */
		void swap_frame_buffer();

		/**
		 * @brief Terminates GLFW (closes all window instances).
		 */
		static void terminate();

		GLFWwindow *get_window() const;

		static Point2 get_mouse_position();

	private:
		static bool _isPolygonMode; // Boolean to either enable or disable polygon rendering
		int _width;					// Window width
		int _height;				// Window height
		std::string _title;

		static void frame_buffer_callback(GLFWwindow *window, int width, int height);
	};
} // namespace Lys