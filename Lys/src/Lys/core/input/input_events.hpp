#pragma once

#include "Lys/core/input/keyboard.hpp"
#include "Lys/core/math/vector2.hpp"

namespace Lys
{
	class InputEventCore
	{
		bool _pressed;
		bool _repeated;

	public:
		InputEventCore() = default;
		virtual ~InputEventCore() = default;

	private:
	};


	class InputKeyEvent
	{
		Key _key;
		KeyPosition _position;

	public:
		InputKeyEvent() = default;
		InputKeyEvent(Key key);
		InputKeyEvent(Key key, KeyPosition position);

		bool is_pressed() const;
		bool is_released() const;
		bool is_repeat() const;

		bool is_just_pressed() const;
		bool is_just_released() const;

		void set_repeat(bool repeat);
		void set_pressed(bool pressed);

		Key get_key() const;

		void reset();

		bool operator==(const InputKeyEvent &other) const { return _key == other._key && _position == other._position; }
	};


	class InputMouseEvent : public InputEventCore
	{
	};


	class MouseMotionEvent : public InputMouseEvent
	{
	public:
		/**
		 * @brief Current mouse position (x, y).
		 */
		MouseMotionEvent(float x, float y);

		Vector2 get_position() const;

	public:
		/**
		 * @brief Updates last mouse position and the displacement between the current and last positions.
		 */
		void update();

	private:
		float _xPos;
		float _yPos;

	public:
		static bool _firstMouse;
		static float _lastMouseX;
		static float _lastMouseY;
	};

} // namespace Lys
