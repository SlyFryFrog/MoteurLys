#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	Logger *Logger::instance()
	{
		if (!_logInstance)
		{
			_logInstance = new Logger();
		}
		return _logInstance;
	}

	void Logger::set_log_file(const std::string &file) { _file = file; }

	Logger::Logger() : _file("rsc/log.txt"), _showLogs(true), _writeLogs(false), _minLogLevel(LogLevel::DEBUG) {}

	const char *Logger::get_log_type(const LogLevel &level)
	{
		// Retrieves the String of the appropriate level
		switch (level)
		{
		case LogLevel::DEBUG:
			return "DEBUG";
		case LogLevel::INFO:
			return "INFO";
		case LogLevel::WARNING:
			return "WARNING";
		case LogLevel::ERROR:
			return "ERROR";
		case LogLevel::CRITICAL:
			return "CRITICAL";
		default:
			return "UNKNOWN";
		}
	}

	void Logger::set_log_level(const LogLevel &level) { _minLogLevel = level; }

	Logger *Logger::_logInstance = nullptr; // Definition with initialization
} // namespace LilyPad
