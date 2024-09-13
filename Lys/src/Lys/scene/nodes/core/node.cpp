#include "node.hpp"

#include "Lys/debug/fps.hpp"

namespace Lys
{
	Node::Node() = default;
	Node::~Node() = default;
	Node::Node(const std::string &name) : _name(name) {}

	void Node::_ready() {}
	void Node::_process(double delta) {}
	void Node::_process_input(const InputEventCore &event) {}
	void Node::_draw() {}
	void Node::_process_mouse_input(const InputEventCore &evet) {}

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

		LYS_ERROR("Child with name '", nodeName, "' not found.");
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

	void Node::update()
	{
		for (auto child : _children)
		{
			child->update();
			call_update_methods(*child);
		}
	}

	void Node::call_update_methods(Node &node)
	{
		node._process(Lys::FPS::get_singleton()->get_delta());
		process_input(node);
		node._draw();
	}

	void Node::init()
	{
		for (auto child : _children)
		{
			child->_ready();
		}
	}

	void Node::process_input(Node &node) {
		// std::vector<InputEventCore> queueForRemoval;

		// // Processes each event and modifies their repeat status
		// for (auto &event : Input::get_singleton()->get_keys_events())
		// {
		// 	node._process_input(event);

		// 	if (event.is_just_pressed())
		// 		event.set_repeat(true);
		// 	else if (event.is_just_released())
		// 		event.set_repeat(true);
		// 	else if (event.is_released())
		// 		queueForRemoval.push_back(event);
		// }

		// // Removes each event that has been released for more than a frame
		// for (auto &event : queueForRemoval)
		// {
		// 	Input::get_singleton()->remove_key_event(event);
		// }
	};
} // namespace Lys
