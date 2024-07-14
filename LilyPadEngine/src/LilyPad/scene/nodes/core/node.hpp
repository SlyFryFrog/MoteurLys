#pragma once

#include "LilyPad/core/utils/typedef.hpp"

namespace LilyPad
{
	class Node
	{
	public:
        Node();

		virtual void _ready();
		virtual void _process();
		virtual void _process_input();
        
	private:
	};
} // namespace LilyPad
