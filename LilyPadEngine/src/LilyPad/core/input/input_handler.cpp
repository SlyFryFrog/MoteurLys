#include "input_handler.hpp"

namespace LilyPad
{
	InputHandler::InputHandler(Key key) : _key(key), _pressed(true) {}
	InputHandler::InputHandler(Key key, KeyPosition position) : _key(key), _position(position) {}

	bool InputHandler::is_pressed() const { return _pressed; }
	bool InputHandler::is_released() const { return !_pressed; }
	
	void InputHandler::set_pressed(bool pressed)
	{
		_pressed = pressed;
	}

	Key InputHandler::get_key() const { return _key; }
} // namespace LilyPad
