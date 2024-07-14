#pragma once

#include <filesystem>
#include <string>

namespace LilyPad
{
	class File
	{
	public:
		File();
		File(const std::string &path);

		bool is_updated() const;
		virtual void update();
		
        std::string read_file(const std::string &path);
		std::string read_file();

	protected:
		std::filesystem::file_time_type _lastTime;
		std::string _path;
	};
} // namespace LilyPad
