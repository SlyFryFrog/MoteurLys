#include "file.hpp"

#include <iostream>
#include <sstream>
#include "Lys/debug/logging.hpp"

namespace Lys
{
	File::File() = default;

	File::~File() = default;

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
			LYS_ERROR("File could not be read at ", path, ". Error code: ", e.what());
		}

		return fileContents;
	}

	std::string File::read_file() const { return read_file(_path); }

	void File::set_path(const std::string &path) { _path = path; }

	std::string File::get_path() const { return _path; }
} // namespace Lys
