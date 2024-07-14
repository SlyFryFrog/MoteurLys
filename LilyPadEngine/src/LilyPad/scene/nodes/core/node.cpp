#include "node.hpp"

namespace LilyPad
{
	Node::Node() = default;
	void Node::_ready() {}
	void Node::_process() {}
	void Node::_process_input() {}

	Node *Node::get_child(const std::string &nodeName)
	{
		for (Node &child : children)
		{
			if (child.Name == nodeName)
			{
				return &child;
			}
		}

		return nullptr;
	}
} // namespace LilyPad
