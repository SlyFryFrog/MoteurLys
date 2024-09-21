#pragma once

#include <string>

#include "Lys/renderer/core/window.hpp"

int main(int argc, char **argv);

namespace Lys
{
	class Application
	{
		static Application *_singleton;
		friend int ::main(int argc, char **argv);

	public:
		std::string name;
		std::string workingDir;

	public:
		Application();

		static Application *get_singleton();

		void run();

		bool init();

		bool is_done() const;

		void shutdown();

		void process_input();

		void render();

		Window *get_window() const;

	private:
		Window *_window;
		bool _isMinimized;
		bool _isRunning;
	};

	/**
	 * @brief Application defined method. Used to define things like the application name. Do not
	 * call any initiating engine methods! That is done automatically by the engine.
	 *
	 * @param argc
	 * @param argv
	 * @return Application*
	 */
	Application *create_application(int argc, char **argv);
} // namespace Lys
