#include "file.hpp"

#include <iostream>
#include <sstream>
#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	File::File() = default;

	File::File(const std::string &path) : _path(path) {}

	bool File::is_updated() const { return std::filesystem::last_write_time(_path) != _lastTime; }

	void File::update() {}

	std::string File::read_file(const std::string &path)
	{
		std::ifstream file;
		std::string fileContents;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			file.open(path);
			std::stringstream fileStream;
			fileStream << file.rdbuf();
			file.close();

			fileContents = fileStream.str();
		}
		catch (std::ifstream::failure &e)
		{
			LILYPAD_ERROR("SHADER::FILE_NOT_SUCCESSFULLY_READY: ", path, " ", e.what());
		}

		return fileContents;
	}

	std::string File::read_file() { return read_file(_path); }

} // namespace LilyPad
