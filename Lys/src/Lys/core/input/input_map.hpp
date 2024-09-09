#pragma once

#include <map>
#include <string>

namespace Lys
{
	struct Action
	{
		int id;
	};


	class InputMap
	{
	public:
		std::map<std::string, Action> input_map;
	};
} // namespace Lys
