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
	public:
		GLFWwindow *window;

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

		void set_dimensions(int width, int height);

		void poll_events();

		void close();

		/**
		 * @brief Closes the window and its context without calling any registered callbacks.
		 *
		 * @note Since this destroys the window without any callbacks, this should only be done on the main thread.
		 */
		void force_close();

		void swap_frame_buffer();

		static void terminate();

	private:
		bool _isPolygonMode; // Boolean to either enable or disable polygon rendering
		int _width;			 // Window width
		int _height;		 // Window height
		std::string _title;

		static void frame_buffer_callback(GLFWwindow *window, int width, int height);

		/**
		 * @brief Processes any input events and will add and remove them to the Input queue.
		 *
		 * This method only performs processing of events. This includes adding and removing said events.
		 *
		 * This does not process repeat events!
		 * This is done outside the function as this is not called per-frame.
		 *
		 * @param window 	Instance of the window for which input is being processed.
		 * @param key		Identifying id for the key being pressed.
		 * @param scancode
		 * @param action
		 * @param mods
		 */
		static void process_input(GLFWwindow *window, int key, int scancode, int action, int mods);
	};
} // namespace LilyPad