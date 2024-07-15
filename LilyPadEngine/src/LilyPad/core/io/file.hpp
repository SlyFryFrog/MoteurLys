#pragma once

#include <filesystem>
#include <string>

namespace LilyPad
{
	class File
	{
	public:
		File();
		explicit File(const std::string &path);

		[[nodiscard]] bool is_updated() const;
		virtual void update();
		
        static std::string read_file(const std::string &path);
		[[nodiscard]] std::string read_file() const;

	protected:
		std::filesystem::file_time_type _lastTime;
		std::string _path;
	};
} // namespace LilyPad
