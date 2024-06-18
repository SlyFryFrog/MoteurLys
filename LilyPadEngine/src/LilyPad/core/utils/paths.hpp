#pragma once

#include <string>

namespace LilyPad
{
	const std::string strip_right_of_slash(const std::string &path);

	const std::string get_exec_path();

	const std::string get_root_directory();
} // namespace LilyPad
