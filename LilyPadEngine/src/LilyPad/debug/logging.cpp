#include "LilyPad/debug/logging.hpp"

#include <chrono>
#include <iomanip>

namespace LilyPad
{
	void Logger::print_log(const LogLevel &level, const std::string &message)
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

	const std::string Logger::get_formatted_time() const
	{
		const auto current_time = std::chrono::system_clock::now();
        const auto current_time_t = std::chrono::system_clock::to_time_t(current_time);
        const std::tm* time_info = std::localtime(&current_time_t);

        // Get the formatted time string from the string stream
        std::ostringstream oss;
        oss << std::put_time(time_info, "%b %d %H:%M:%S");
        const std::string formatted_time = oss.str();

		return formatted_time;
	}

	Logger *Logger::_logInstance = nullptr; // Definition with initialization
} // namespace LilyPad
