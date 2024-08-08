#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "LilyPad/core/input/input_handler.hpp"

namespace LilyPad
{
	class Input
	{
		static Input *_singleton;

	public:
		static Input *get_singleton();

		std::vector<InputHandler> get_keys_pressed() const;

		void add_key_event(const InputHandler &event);
		void remove_key_event(const InputHandler &event);

	private:
		Input();
		~Input();

		std::vector<InputHandler> _events;
	};
} // namespace LilyPad
