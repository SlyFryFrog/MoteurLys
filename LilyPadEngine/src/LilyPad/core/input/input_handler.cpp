#include "input_handler.hpp"

namespace LilyPad
{
	InputHandler::InputHandler(Key key) : _key(key) {}
	InputHandler::InputHandler(Key key, KeyPosition position) : _key(key), _position(position) {}

	bool InputHandler::is_pressed() const { return _pressed; }
    bool InputHandler::is_released() const { return !_pressed; }
    
    Key InputHandler::get_key() const { return _key; }
} // namespace LilyPad
