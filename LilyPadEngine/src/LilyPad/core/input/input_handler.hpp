#pragma once

#include "LilyPad/core/input/keyboard.hpp"

namespace LilyPad
{
	class InputHandler
	{
	public:
		InputHandler(Key key);
		InputHandler(Key key, KeyPosition position);

		bool is_pressed() const;
		bool is_released() const;

		Key get_key() const;
		
		bool operator==(const InputHandler &other) const 
		{ 
			return _key == other._key && _position == other._position; 
		}

	protected:
		bool _pressed = false;
		Key _key;
		KeyPosition _position;

	private:
	};
} // namespace LilyPad
