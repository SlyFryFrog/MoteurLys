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
		 * @brief Creates an event log if the level is at least the minimum level currentl set. Will also print the log
		 * to the console if that option is enabled.
		 *
		 * @param level   Level of the log being recoded.
		 * @param message Message to write for the log.
		 */
		template <typename... Args>
		void log(const LogLevel level, Args... args)
		{
			// Ignores any logging lower than the minimum
			if (level < minLogLevel || (writeLogs && showLogs))
				return;

			// Gets time
			std::time_t now = std::time(nullptr);
			char time[100];
			// Month, Day, Hour, Minute, Second
			std::strftime(time, sizeof(time), "%b %d %H:%M:%S", std::localtime(&now));

			std::stringstream logStream;
			logStream << "[" << get_log_type(level) << "] " << time << " : ";
			append_to_stream(logStream, args...);

			std::string logMessage = logStream.str();

			if (showLogs)
			{
				std::cout << logMessage << std::endl;
			}
			if (writeLogs)
			{
				std::lock_guard<std::mutex> guard(logMutex);
				std::ofstream fileStream(file, std::ios::app);
				if (fileStream.is_open())
				{
					fileStream << logMessage << std::endl;
				}
				else
				{
					std::cerr << "Unable to open the log file at " << file << std::endl;
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
		void set_log_level(LogLevel level);

	private:
		/**
		 * @brief Construct a new Logger object.
		 */
		Logger();

		/**
		 * @brief Appends a single argument to a stringstream.
		 *
		 * @tparam Arg The type of the argument to be appended.
		 * @param stream The stringstream to which the argument will be appended.
		 * @param arg The argument to be appended to the stringstream.
		 */
		template <typename Arg>
		void append_to_stream(std::stringstream &stream, Arg arg)
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
		void append_to_stream(std::stringstream &stream, Arg arg, Args... args)
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
		static const char *get_log_type(LogLevel level);

		LogLevel minLogLevel;		// Minimum level to be logged.
		static Logger *logInstance; // Static pointer to the current instance of Logger.
		std::string file;			// Relative path to the log file being written to.
		bool showLogs;				// When set to true, displays all logs to the console.
		bool writeLogs;				// When set to true, writes all logs to the given file.
		std::mutex logMutex;		// Locks logger from writing to file when another thread is.
	};
} // namespace LilyPad
