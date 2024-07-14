#pragma once

#include <memory>
#include <string>
#include <vector>
#include "LilyPad/core/utils/typedef.hpp"
#include "LilyPad/debug/logging.hpp"
namespace LilyPad
{
	class Node
	{
	public:
		Node();

		virtual void _ready();
		virtual void _process(double delta);
		virtual void _process_input();

		std::string get_name() const;
		void set_name(const std::string &name);

		void add_child(std::shared_ptr<Node> child);

		template <typename T>
		std::shared_ptr<T> get_child(const std::string &nodeName)
		{
			for (auto &child : _children)
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
						LILYPAD_ERROR("Failed to cast child named '", nodeName, "' to type ", typeid(T).name());
						return nullptr;
					}
				}
			}
			LILYPAD_ERROR("Child with name '", nodeName, "' not found.");
			return nullptr;
		}

		virtual ~Node() = default;

	private:
		std::string _name;
		std::vector<std::shared_ptr<Node>> _children;
		std::shared_ptr<Node> _parent;
	};
} // namespace LilyPad
