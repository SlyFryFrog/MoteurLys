#include "node.hpp"

namespace LilyPad
{
	Node::Node() = default;
	Node::~Node() = default;

	void Node::_ready() {}
	void Node::_process(double delta) {}
	void Node::_process_input() {}

	void Node::set_name(const std::string &name) { _name = name; }
	void Node::add_child(std::shared_ptr<Node> child) { _children.push_back(child); }

	std::string Node::get_name() const { return _name; }
} // namespace LilyPad
