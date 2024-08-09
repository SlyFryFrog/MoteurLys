#include "input.hpp"

#include <algorithm>
#include <memory>
#include "LilyPad/debug/logging.hpp"

namespace LilyPad
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
		for (const auto &event : get_singleton()->_events)
		{
			if (event.get_key() == key)
				return event.is_pressed();
		}

		return false;
	}

	bool Input::is_released(Key key) { return !is_pressed(key); }

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


} // namespace LilyPad
