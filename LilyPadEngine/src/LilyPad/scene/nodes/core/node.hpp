#pragma once

#include "LilyPad/core/utils/typedef.hpp"
#include <vector>
#include <string>

namespace LilyPad
{
	class Node
	{
	public:
        Node();

		std::string Name;

		virtual void _ready();
		virtual void _process();
		virtual void _process_input();

		Node *get_child(const std::string &nodeName);
        
	private:
		std::vector<Node> children;
	};
} // namespace LilyPad
