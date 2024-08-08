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

		void set_pressed(bool pressed);

		Key get_key() const;
		
		bool operator==(const InputHandler &other) const 
		{ 
			return _key == other._key && _position == other._position; 
		}

	protected:
		KeyAction _action;
		Key _key;
		KeyPosition _position;
		
		bool _pressed;

	private:
	};
} // namespace LilyPad
