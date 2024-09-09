#include "application.hpp"

#include "Lys/debug/fps.hpp"
#include "Lys/renderer/core/renderer.hpp"
#include "Lys/core/input/input_manager.hpp"

namespace Lys
{
	Application *Application::_singleton = nullptr;

	Application *Application::get_singleton()
	{
		if (!_singleton)
			_singleton = new Application();

		return _singleton;
	}

	Application::Application() : _isMinimized(false), _isRunning(true) {}

	void Application::run()
	{
		while (!is_done() && !_window->is_done())
		{
			Renderer::get_singleton()->clear();
			LYS_FPS_UPDATE();

			if (!_isMinimized)
			{
			}

			process_input();

			_window->poll_events();
			_window->swap_frame_buffer();
		}
	}

	bool Application::init()
	{
		_window = new Window(500, 500, name);
		_window->initialize();

		return _isRunning;
	}

	bool Application::is_done() const { return !_isRunning; }

	void Application::shutdown() {}

	void Application::process_input() {}

	Window *Application::get_window() const
	{
		return _window;
	}
} // namespace Lys