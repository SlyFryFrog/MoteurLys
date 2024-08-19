#pragma once

#include <string>

namespace Lys
{
	std::string strip_right_of_slash(const std::string &path);

	std::string get_exec_path();

	std::string get_root_directory();
} // namespace Lys
