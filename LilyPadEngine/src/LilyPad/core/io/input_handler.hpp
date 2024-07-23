#pragma once

namespace LilyPad
{
	class InputHandler
	{
	public:
		bool is_pressed() const;

	protected:
		bool _pressed = false;

	private:
	};
} // namespace LilyPad
