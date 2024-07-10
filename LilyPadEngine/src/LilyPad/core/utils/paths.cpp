#include "LilyPad/core/utils/paths.hpp"

#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#elifdef __linux__
#include <unistd.h>  // For readlink
#include <limits.h>  // For PATH_MAX
#endif

namespace LilyPad
{
	std::string strip_right_of_slash(const std::string &path)
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
	std::string get_exec_path()
	{
#ifdef _WIN32
		wchar_t path[MAX_PATH] = {0};
		GetModuleFileNameW(NULL, path, MAX_PATH);
		std::wstring ws(path);
		// your new String
		std::string buff(ws.begin(), ws.end());
#else
		char buff[PATH_MAX];
		readlink("/proc/self/exe", buff, sizeof(buff) - 1);
#endif
		return buff;
	}

	std::string get_root_directory() { return strip_right_of_slash(get_exec_path()); }
} // namespace LilyPad
