#pragma once

#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

#define LILYPAD_DEBUG(...) LilyPad::Logger::instance()->log(LilyPad::LogLevel::DEBUG, __VA_ARGS__)
#define LILYPAD_INFO(...) LilyPad::Logger::instance()->log(LilyPad::LogLevel::INFO, __VA_ARGS__)
#define LILYPAD_WARNING(...) LilyPad::Logger::instance()->log(LilyPad::LogLevel::WARNING, __VA_ARGS__)
#define LILYPAD_ERROR(...) LilyPad::Logger::instance()->log(LilyPad::LogLevel::ERROR, __VA_ARGS__)
#define LILYPAD_CRITICAL(...) LilyPad::Logger::instance()->log(LilyPad::LogLevel::CRITICAL, __VA_ARGS__)

namespace LilyPad
{
	/**
	 * @brief Contains the logging levels ranging from DEBUG (0) to CRITICAL (4).
	 */
	enum class LogLevel
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		CRITICAL
	};

	/**
	 * @brief Contains constants of color codes for coloring text in terminal.
	 */
	struct TextColor
	{
		const std::string RED = "\033[31m";
		const std::string GREEN = "\033[32m";
		const std::string YELLOW = "\033[33m";
		const std::string DEFAULT = "\033[39m";
	};

	/**
	 * @brief Class for recording events to console and a file.
	 */
	class Logger
	{
	public:
		/**
		 * @brief Gets the current instance of the Logger.
		 *
		 * @return Logger* Pointer to the Logger instance.
		 */
		static Logger *instance();

		/**
		 * @brief 
		 */
		template <typename... Args>
		void log(const LogLevel &level, Args... args)
		{
			// Ignores any logging lower than the minimum
			if (level < _minLogLevel || (_writeLogs && _showLogs))
			{
				return;
			}

			std::stringstream logStream;
			logStream << "[" << get_log_type(level) << "] " << get_formatted_time() << " : ";
			append_to_stream(logStream, args...);

			const std::string logMessage = logStream.str();

			if (_showLogs)
			{
				print_log(level, logMessage);
			}
			if (_writeLogs)
			{
				std::lock_guard<std::mutex> guard(_logMutex);
				std::ofstream fileStream(_file, std::ios::app);
				if (fileStream.is_open())
				{
					fileStream << logMessage << std::endl;
				}
				else
				{
					std::cerr << "Unable to open the log file at " << _file << std::endl;
				}
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

		/**
		 * @brief Prints the log to the console with the appropriate color.
		 */
		void print_log(const LogLevel &level, const std::string &message);

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

		const std::string get_formatted_time() const;

		std::string _file;			// Relative path to the log file being written to.
		bool _showLogs;				// When set to true, displays all logs to the console.
		bool _writeLogs;				// When set to true, writes all logs to the given file.
		std::mutex _logMutex;		// Locks logger from writing to file when another thread is.
		LogLevel _minLogLevel;		// Minimum level to be logged.
		TextColor _textColors;
		static Logger *_logInstance; // Static pointer to the current instance of Logger.
	};
} // namespace LilyPad
