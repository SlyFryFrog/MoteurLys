#pragma once

#include <vector>
#include "LilyPad/core//io/key.hpp"

namespace LilyPad
{
	class Input
	{
		static Input *_singleton;

	public:
		std::vector<Key> keys_pressed;
		static Input *get_singleton();

	private:
		Input();
		~Input();
	};
} // namespace LilyPad
