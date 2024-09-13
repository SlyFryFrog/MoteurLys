#include "Lys/debug/logging.hpp"

#include <chrono>
#include <iomanip>

namespace Lys
{
	std::string LogColors::DEFAULT = "\033[39m";	 // Default
	std::string LogColors::DEBUG = "\033[39m";		 // Gray
	std::string LogColors::INFO = "\033[39m";		 // Default
	std::string LogColors::WARNING = "\033[33m";	 // Yellow
	std::string LogColors::ERROR = "\033[38;5;208m"; // Orange
	std::string LogColors::CRITICAL = "\033[31m";	 // Red
	Logger *Logger::_singleton = nullptr;			 // Definition with initialization

	Logger::Logger() :
		_logFile(nullptr), _showLogs(true), _writeLogs(false), _showTimestamp(true), _minLogLevel(LogLevel::DEBUG),
		_timeFormat(new std::string("%H:%M:%S")), _configFile(nullptr)
	{
		_singleton = this;
	}

	Logger::~Logger()
	{
		delete _singleton;
		delete _timeFormat;
	}

	void Logger::print_log(const LogLevel &level, const std::string &message) const
	{
		std::string color;

		switch (level)
		{
		case LogLevel::DEBUG:
			color = LogColors::DEBUG;
			break;
		case LogLevel::INFO:
			color = LogColors::DEFAULT;
			break;
		case LogLevel::WARNING:
			color = LogColors::WARNING;
			break;
		case LogLevel::ERROR:
			color = LogColors::ERROR;
			break;
		case LogLevel::CRITICAL:
			color = LogColors::CRITICAL;
			break;
		default:
			color = LogColors::DEFAULT;
			break;
		}

		std::println("{0} {1} {2}", color, message, LogColors::DEFAULT);
	}

	Logger *Logger::get_singleton()
	{
		if (!_singleton)
		{
			_singleton = new Logger();
		}
		return _singleton;
	}

	void Logger::set_log_file(const std::string &file) { _logFile = std::make_unique<std::string>(file); }

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

	std::string Logger::get_formatted_time(const std::string *timeFormat)
	{
		const auto current_time = std::chrono::system_clock::now();
		const auto current_time_t = std::chrono::system_clock::to_time_t(current_time);
		const std::tm *timeInfo = std::localtime(&current_time_t);

		// Get the formatted time string from the string stream
		std::ostringstream oss;
		oss << std::put_time(timeInfo, timeFormat->c_str());
		const std::string formattedTime = oss.str();

		return formattedTime;
	}

} // namespace Lys
