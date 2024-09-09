#include "input_events.hpp"

namespace Lys
{
	InputKeyEvent::InputKeyEvent(Key key) : _key(key) {}
	Key InputKeyEvent::get_key() const
	{
		return _key;
	}

	MouseMotionEvent::MouseMotionEvent(float x, float y) : _xPos(x), _yPos(y) {}

	Vector2 MouseMotionEvent::get_position() const { return {_xPos, _yPos}; }

	void MouseMotionEvent::update()
	{
		if (_firstMouse)
		{
			_lastMouseX = _xPos;
			_lastMouseY = _yPos;
		}
		else
		{
			_xPos -= _lastMouseX;
			_yPos -= _lastMouseY;
		}
	}

	bool MouseMotionEvent::_firstMouse = true;
	float MouseMotionEvent::_lastMouseX = 0.0f;
	float MouseMotionEvent::_lastMouseY = 0.0f;
} // namespace Lys
