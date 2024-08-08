#include "node.hpp"

namespace LilyPad
{
	Node::Node() = default;
	Node::~Node() = default;
	Node::Node(const std::string &name) : _name(name) {}

	void Node::_ready() {}
	void Node::_process(double delta) {}
	void Node::_process_input(const Input &events) {}
	void Node::_draw() {}

	void Node::set_name(const std::string &name) { _name = name; }
	void Node::add_child(std::shared_ptr<Node> child) { _children.push_back(child); }

	std::shared_ptr<Node> Node::get_child(const std::string &nodeName)
	{
		for (const auto &child : _children)
		{
			if (child->get_name() == nodeName)
			{
				return child;
			}
		}

		LILYPAD_ERROR("Child with name '", nodeName, "' not found.");
		return nullptr;
	}

	std::string Node::get_name() const { return _name; }

	std::shared_ptr<Node> Node::get_parent() const { return _parent; }

	void Node::queue_destroy()
	{
		for (auto &child : _children)
		{
			child->queue_destroy();
		}

		_children.clear(); // Clears the array
		_parent.reset();   // Sets parent to nullptr
	}
} // namespace LilyPad
