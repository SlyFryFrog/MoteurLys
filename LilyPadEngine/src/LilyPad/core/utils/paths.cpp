#include "LilyPad/core/utils/paths.hpp"

#include <filesystem>

#ifdef __linux__
#include <limits.h>
#include <unistd.h>
#endif

namespace LilyPad
{
	const std::string strip_right_of_slash(const std::string &path)
	{
		std::string::size_type index;
#ifdef _WIN32
		index = path.find_last_of('\\');
#else
		index = path.find_last_of('/');
#endif
		return path.substr(0, index);
	}

	/**
	 * @return std::string Absolute path to the executable.
	 */
	const std::string get_exec_path()
	{
		char buff[PATH_MAX];
#ifdef __linux__
		readlink("/proc/self/exe", buff, sizeof(buff) - 1);
#endif
		return std::string(buff);
	}

	const std::string get_root_directory()
	{
		return strip_right_of_slash(get_exec_path());
	}
} // namespace LilyPad
