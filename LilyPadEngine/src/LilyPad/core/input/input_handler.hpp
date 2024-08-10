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
		bool is_repeat() const;

		bool is_just_pressed() const;
		bool is_just_released() const;
		
		void set_repeat(bool repeat);		
		void set_pressed(bool pressed);

		Key get_key() const;
		
		bool operator==(const InputHandler &other) const 
		{ 
			return _key == other._key && _position == other._position; 
		}

	private:
		Key _key;
		KeyPosition _position;
		bool _repeat = false;
		bool _pressed = true;

	};
} // namespace LilyPad
