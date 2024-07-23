#pragma once

#include <vector>
#include <GLFW/glfw3.h>
#include "LilyPad/core/io/key.hpp"
#include "LilyPad/core/io/input_handler.hpp"

namespace LilyPad
{
	class Input
	{
		static Input *_singleton;

	public:
		std::vector<Key> keys_pressed;
		
		static Input *get_singleton();
		void add_key_event(const Key &key, const InputHandler &event);

	private:
		Input();
		~Input();
	};
} // namespace LilyPad
