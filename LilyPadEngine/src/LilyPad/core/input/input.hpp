#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <vector>
#include "LilyPad/core/input/input_handler.hpp"

namespace LilyPad
{
	class Input
	{
		static Input *_singleton;

	public:
		static Input *get_singleton();

		static bool is_pressed(Key key);
		static bool is_released(Key key);

		std::vector<InputHandler> &get_keys_events();
		void add_key_event(const InputHandler &event);
		void remove_key_event(const InputHandler &event);

		std::shared_ptr<InputHandler> get_event(Key key) const;

	private:
		Input();
		~Input();

		std::vector<InputHandler> _events;
	};
} // namespace LilyPad
