#pragma once

#include <fstream>
#include <mutex>
#include <print>
#include <sstream>
#include <string>

#define LILYPAD_DEBUG(...) LilyPad::Logger::get_singleton()->log(LilyPad::LogLevel::DEBUG, __VA_ARGS__)
#define LILYPAD_INFO(...) LilyPad::Logger::get_singleton()->log(LilyPad::LogLevel::INFO, __VA_ARGS__)
#define LILYPAD_WARNING(...) LilyPad::Logger::get_singleton()->log(LilyPad::LogLevel::WARNING, __VA_ARGS__)
#define LILYPAD_ERROR(...) LilyPad::Logger::get_singleton()->log(LilyPad::LogLevel::ERROR, __VA_ARGS__)
#define LILYPAD_CRITICAL(...) LilyPad::Logger::get_singleton()->log(LilyPad::LogLevel::CRITICAL, __VA_ARGS__)

namespace LilyPad
{
	enum class LogLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		CRITICAL
	};

	/**
	 * @brief Arbitrary colors for displaying different levels of logs. Can be changed to any other color in the form of
	 * ANSI Color Escape.
	 */
	struct LogColors
	{
		static std::string DEFAULT;
		static std::string DEBUG;
		static std::string INFO;
		static std::string WARNING;
		static std::string ERROR;
		static std::string CRITICAL;
	};

	/**
	 * @brief Class for recording events to console and a file.
	 */
	class Logger
	{
		static Logger *_singleton;

	public:
		/**
		 * @brief Gets the current instance of the Logger.
		 *
		 * @return Logger* Pointer to the Logger instance.
		 */
		static Logger *get_singleton();

		/**
		 * @brief
		 */
		template <typename... Args>
		void log(const LogLevel &level, Args... args)
		{
			// Ignores any logging lower than the minimum
			if (level < _minLogLevel || (_writeLogs && _showLogs))
				return;

			std::stringstream logStream; // Writes all logs to stream before outputting to console/file

			// Adds timestamp next to the log type and message if enabled
			if (_timeFormat && _showTimestamp)
				logStream << "[" << get_log_type(level) << "] " << get_formatted_time(_timeFormat) << " : ";
			else
				logStream << "[" << get_log_type(level) << "] : ";

			append_to_stream(logStream, args...);

			const std::string logMessage = logStream.str();

			if (_showLogs)
				print_log(level, logMessage);
			if (_writeLogs)
			{
				std::lock_guard<std::mutex> guard(_logMutex);
				std::ofstream fileStream(_file, std::ios::app); // Sets mode to append

				if (fileStream.is_open())
					fileStream << logMessage << std::endl;
				else
					std::println("Unable to open the log file at ", _file);
			}
		}

		/**
		 * @brief Set the log file.
		 *
		 * @param file Relative path to the file.
		 */
		void set_log_file(const std::string &file);

		/**
		 * @brief Set the minimum log level to be recorded; defaults to DEBUG.
		 *
		 * @param level Minimum log level to be recorded.
		 */
		void set_log_level(const LogLevel &level);

	private:
		/**
		 * @brief Construct a new Logger object.
		 */
		Logger();

		~Logger();

		/**
		 * @brief Prints the log to the console with the appropriate color.
		 */
		void print_log(const LogLevel &level, const std::string &message) const;

		/**
		 * @brief Appends a single argument to a stringstream.
		 *
		 * @tparam Arg The type of the argument to be appended.
		 * @param stream The stringstream to which the argument will be appended.
		 * @param arg The argument to be appended to the stringstream.
		 */
		template <typename Arg>
		static void append_to_stream(std::stringstream &stream, Arg arg)
		{
			stream << arg;
		}

		/**
		 * @brief Recursively appends multiple arguments to a stringstream.
		 *
		 * This function appends multiple arguments to the provided stringstream by recursively appending each argument
		 * in the parameter pack.
		 *
		 * @tparam Arg The type of the argument to be appended.
		 * @tparam Args The types of remaining arguments.
		 * @param stream The stringstream to which the argument will be appended.
		 * @param arg The first argument to be appended to the stringstream.
		 * @param args The remaining arguments to be appended to the stringstream.
		 */
		template <typename Arg, typename... Args>
		static void append_to_stream(std::stringstream &stream, Arg arg, Args... args)
		{
			stream << arg;
			append_to_stream(stream, args...);
		}

		/**
		 * @brief Get the log level as a const char *.
		 *
		 * @param level 		LogLevel.
		 * @return const char* 	String equivalent of the LogLevel.
		 */
		static const char *get_log_type(const LogLevel &level);

		[[nodiscard]] static std::string get_formatted_time(const std::string *timeFormat);

		bool _showLogs;
		bool _writeLogs;
		bool _showTimestamp;
		std::mutex _logMutex;
		std::string _file;
		std::string *_timeFormat;
		LogLevel _minLogLevel;
	};
} // namespace LilyPad
