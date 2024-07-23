#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "LilyPad/core/io/input_handler.hpp"

namespace LilyPad
{
	class Input
	{
		static Input *_singleton;

	public:
		std::vector<InputHandler> keys_pressed;

		static Input *get_singleton();
		void add_key_event(const InputHandler &event);

	private:
		Input();
		~Input();
	};
} // namespace LilyPad
