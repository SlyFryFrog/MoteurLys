#include "logging.hpp"

namespace LilyPad
{
	Logger *Logger::instance()
	{
		if (!logInstance)
		{
			logInstance = new Logger();
		}
		return logInstance;
	}

	void Logger::set_log_file(const std::string &file) { this->file = file; }

	Logger::Logger() : showLogs(true), writeLogs(false), minLogLevel(LogLevel::DEBUG), file("rsc/log.txt") {}

	const char *Logger::get_log_type(LogLevel level)
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

	void Logger::set_log_level(LogLevel minLevel) { minLogLevel = minLevel; }

	Logger *Logger::logInstance = nullptr; // Definition with initialization
} // namespace LilyPad
