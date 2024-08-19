#include "input.hpp"

#include <algorithm>
#include <memory>
#include "Lys/debug/logging.hpp"

namespace Lys
{
	Input *Input::_singleton = nullptr;

	std::vector<InputHandler> &Input::get_keys_events() { return _events; }

	Input *Input::get_singleton()
	{
		if (!_singleton)
			_singleton = new Input();

		return _singleton;
	}

	bool Input::is_pressed(const Key key)
	{
		for (auto &event : Input::get_singleton()->get_keys_events())
		{
			if (event.get_key() == key)
			{
				return event.is_pressed();
			}
		}

		return false;
	}

	bool Input::is_released(Key key)
	{
		for (auto &event : Input::get_singleton()->get_keys_events())
		{
			if (event.get_key() == key)
			{
				return event.is_released();	
			}
		}

		// Base case where button isn't in inputs vector
		return true;
	}

	bool Input::is_just_pressed(Key key)
	{
		for (auto &event : Input::get_singleton()->get_keys_events())
		{
			if (event.get_key() == key)
			{
				return event.is_just_pressed();
			}
		}

		return false;
	}

	bool Input::is_just_released(Key key)
	{
		for (auto &event : Input::get_singleton()->get_keys_events())
		{
			if (event.get_key() == key)
			{
				return event.is_just_released();
			}
		}

		return false;
	}

	void Input::add_key_event(const InputHandler &event) { _events.push_back(event); }

	void Input::remove_key_event(const InputHandler &event)
	{
		_events.erase(std::remove(_events.begin(), _events.end(), event), _events.end());
	}

	InputHandler *Input::get_event(const Key key)
	{
		for (auto &event : _events)
		{
			if (event.get_key() == key)
				return &event;
		}

		return nullptr;
	}

	Input::Input() { _singleton = this; }

	Input::~Input() { delete _singleton; }


} // namespace Lys
