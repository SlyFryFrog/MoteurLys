#pragma once

#include <string>

namespace LilyPad
{
	std::string strip_right_of_slash(const std::string &path);

	std::string get_exec_path();
} // namespace LilyPad
