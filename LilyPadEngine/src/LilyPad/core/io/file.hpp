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

		/**
		 * @brief Checks if that last write time has changed since the last check.
		 *
		 * @return true if the file has been updated since _lastTime.
		 * @return false if the file has not been updated since _lastTime.
		 */
		[[nodiscard]] bool is_updated() const;

		/**
		 * @brief Empty implementation that should be overrided to add functionality.
		 */
		virtual void update();

		/**
		 * @brief Returns the contents of the given file. Will always catch errors.
		 *
		 * @param path Path to the file being read. Should be absolute.
		 * @return std::string Contents of the file being read. If unable to read the requested file, will return an
		 * empty string.
		 */
		static std::string read_file(const std::string &path);

		/**
		 * @brief Returns the contents of the previously set file path. Will always catch errors.
		 *
		 * @return std::string Contents of the file being read. If unable to read the requested file, will return an
		 * empty string.
		 */
		[[nodiscard]] std::string read_file() const;

		void set_path(const std::string &path);

		std::string get_path() const;

	protected:
		std::filesystem::file_time_type _lastTime;
		std::string _path;
	};
} // namespace LilyPad
