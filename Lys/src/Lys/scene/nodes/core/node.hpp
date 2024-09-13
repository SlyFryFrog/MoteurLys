#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Lys/core/input/input_events.hpp"
#include "Lys/debug/logging.hpp"

namespace Lys
{
	class Node
	{
	public:
		Node();
		explicit Node(const std::string &name);
		virtual ~Node();

		virtual void _ready();
		virtual void _process(double delta);
		virtual void _process_input(const InputEventCore &event);
		virtual void _draw();
		virtual void _process_mouse_input(const InputEventCore &event);

		[[nodiscard]] std::string get_name() const;
		void set_name(const std::string &name);

		void add_child(std::shared_ptr<Node> child);

		template <typename T>
		std::shared_ptr<T> get_child(const std::string &nodeName)
		{
			for (const auto &child : _children)
			{
				if (child->get_name() == nodeName)
				{
					auto casted_child = std::dynamic_pointer_cast<T>(child);
					if (casted_child)
					{
						return casted_child;
					}
					else
					{
						LYS_ERROR("Failed to cast child named '", nodeName, "' to type ", typeid(T).name());
						return nullptr;
					}
				}
			}

			LYS_ERROR("Child with name '", nodeName, "' not found.");
			return nullptr;
		}

		std::shared_ptr<Node> get_child(const std::string &nodeName);

		template <typename T>
		std::shared_ptr<T> get_parent()
		{
			auto casted_parent = std::dynamic_pointer_cast<T>(_parent);
			if (casted_parent)
			{
				return casted_parent;
			}
			else
			{
				LYS_ERROR("Failed to cast parent named '", _parent->_name, "' to type ", typeid(T).name());
				return nullptr;
			}
		}

		std::shared_ptr<Node> get_parent() const;

		void queue_destroy();

		void update();

		void init();

	private:
		void call_update_methods(Node &node);
		void process_input(Node &node);

	private:
		std::string _name;
		std::vector<std::shared_ptr<Node>> _children;
		std::shared_ptr<Node> _parent;
	};
} // namespace Lys
