#pragma once

#include <filesystem>
#include <string>

namespace LilyPad
{
	class File
	{
	public:
		File();
		virtual ~File();
		explicit File(const std::string &path);

		[[nodiscard]] bool is_updated() const;
		virtual void update();
		
		/**
		 * @brief 
		 * 
		 * @param path Path to the file being read. Should be absolute.
		 * @return std::string Contents of the file being read. If unable to read the requested file, will return an empty string.
		 */
        static std::string read_file(const std::string &path);
		[[nodiscard]] std::string read_file() const;

	protected:
		std::filesystem::file_time_type _lastTime;
		std::string _path;
	};
} // namespace LilyPad
