#include "LilyPad/core/utils/paths.hpp"

#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <climits>
#include <unistd.h>
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
		std::string buff;
#ifdef _WIN32
		wchar_t path[MAX_PATH] = {0};
		GetModuleFileNameW(NULL, path, MAX_PATH);
		std::wstring ws(path);
		// your new String
		buff = std::string(ws.begin(), ws.end());
#else
		char path[PATH_MAX];
		ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
		if (len != -1)
		{
			path[len] = '\0'; // Null-terminate the buffer
			buff = std::string(path);
		}
		else
		{
			throw std::runtime_error("Failed to read the executable path");
		}
#endif
		return buff;
	}

	std::string get_root_directory() { return strip_right_of_slash(get_exec_path()); }
} // namespace LilyPad
