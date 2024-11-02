#include "input_manager.hpp"

#include "Lys/renderer/core/window.hpp"

namespace Lys
{
	InputManager *InputManager::_singleton = nullptr;
	InputManager *InputManager::get_singleton() { return _singleton; }

	void InputManager::init() { _singleton = new InputManager(); }

	InputManager::InputManager() = default;
	InputManager::~InputManager() { delete _singleton; }

	std::vector<InputEventCore> InputManager::get_events() const { return _events; }

	void InputManager::add_key_event(const InputKeyEvent &event) {}
	void InputManager::add_mouse_event(const InputMouseEvent &event) {}

	void InputManager::_process_input_callback(GLFWwindow *window, const int key,
											   const int scancode, const int action, const int mods)
	{
		const auto *windowInstance = static_cast<Window *>(glfwGetWindowUserPointer(window));
		Key keyCode = convert_code(key);
		bool isRegistered = false;

		// Only checks the key for valid InputKeyEvents
		for (auto &event : _singleton->get_events())
		{
			if (const InputKeyEvent *keyEvent = dynamic_cast<const InputKeyEvent *>(&event))
			{
				if (keyEvent->get_key() != keyCode)
				{
					continue;
				}
				isRegistered = true;
			}
		}

		if (!isRegistered)
		{
			InputKeyEvent event(keyCode);
			_singleton->add_key_event(event);
		}
		else
		{
			if (action == GLFW_RELEASE)
			{
				for (auto &event : _singleton->get_events())
				{
					if (const InputKeyEvent *keyEvent = dynamic_cast<const InputKeyEvent *>(&event))
					{
					}
					else if (const InputMouseEvent *mouseEvent =
								 dynamic_cast<const InputMouseEvent *>(&event))
					{
					}
				}
			}
		}
	}

	void InputManager::_process_mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
	{
		const auto xpos = static_cast<float>(xposIn);
		const auto ypos = static_cast<float>(yposIn);
		MouseMotionEvent event(xposIn, yposIn);

		if (MouseMotionEvent::_firstMouse)
		{
			MouseMotionEvent::_lastMouseX = xpos;
			MouseMotionEvent::_lastMouseY = ypos;
			MouseMotionEvent::_firstMouse = false;
		}

		float xOffset = xpos - MouseMotionEvent::_lastMouseX;
		float yOffset = MouseMotionEvent::_lastMouseY -
			ypos; // reversed since y-coordinates go from bottom to top

		MouseMotionEvent::_lastMouseX = xpos;
		MouseMotionEvent::_lastMouseY = ypos;

		_singleton->add_mouse_event(event);
	}

	bool InputManager::is_pressed(const Key &key)
	{
		for (auto entry : _singleton->_keysPressed)
		{
			if (entry == key)
			{
				return true;
			}
		}

		return false;
	}
} // namespace Lys
