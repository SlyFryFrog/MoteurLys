#pragma once

#ifdef OPENGL
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <vector>
#include "Lys/core/input/input_events.hpp"
#include "Lys/core/math/vector2.hpp"

namespace Lys
{
	enum class InputType
	{
		MOUSE_BUTTON,
		MOUSE_MOVEMENT,
		KEY_BUTTON
	};

	class InputManager
	{
		static InputManager *_singleton;
		Vector2 _mousePosition;
		std::vector<Key> _keysPressed;
		std::vector<InputEventCore> _events;

	public:
		static InputManager *get_singleton();

		std::vector<InputEventCore> get_events() const;
		void add_key_event(const InputKeyEvent &event);
		void add_mouse_event(const InputMouseEvent &event);

		/**
		 * @brief Processes any input events and will add and remove them to the Input queue.
		 *
		 * This method only performs processing of events. This includes adding and removing said
		 * events.
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
		static void _process_input_callback(GLFWwindow *window, const int key, const int scancode,
											const int action, const int mods);
		static void _process_mouse_callback(GLFWwindow *window, double xposIn, double yposIn);
		static bool is_pressed(const Key &key);

	private:
		InputManager();
		~InputManager();
	};
} // namespace Lys
