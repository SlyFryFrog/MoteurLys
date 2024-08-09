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
		
		void set_repeat(bool repeat);
		KeyAction get_action() const;
		void set_action(KeyAction action);
		
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
		bool _repeat = false;
		bool _pressed = true;

	private:
	};
} // namespace LilyPad
