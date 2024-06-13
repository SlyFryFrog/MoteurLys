#include "LilyPad/debug/logging.hpp"

namespace LilyPad
{
	void Logger::print_log(const LogLevel &level, std::string message)
	{
		std::string color;

		switch (level)
		{
		case LogLevel::DEBUG:
			color = _textColors.DEFAULT;
			break;
		case LogLevel::INFO:
			color = _textColors.DEFAULT;
			break;
		case LogLevel::WARNING:
			color = _textColors.YELLOW;
			break;
		case LogLevel::ERROR:
			color = _textColors.RED;
			break;
		case LogLevel::CRITICAL:
			color = _textColors.RED;
			break;
		default:
			color = _textColors.DEFAULT;
			break;
		}

		std::cout << color << message << _textColors.DEFAULT << "\n";
	}

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
