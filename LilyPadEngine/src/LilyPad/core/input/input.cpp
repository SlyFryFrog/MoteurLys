#include "input.hpp"

#include <algorithm>

namespace LilyPad
{
	Input *Input::_singleton = nullptr;

	std::vector<InputHandler> Input::get_keys_pressed() const { return _events; }

	Input *Input::get_singleton()
	{
		if (!_singleton)
			_singleton = new Input();

		return _singleton;
	}

	void Input::add_key_event(const InputHandler &event) { _events.emplace_back(event); }

	void Input::remove_key_event(const InputHandler &event)
	{
		_events.erase(std::remove(_events.begin(), _events.end(), event), _events.end());
	}

	Input::Input() { _singleton = this; }

	Input::~Input() { delete _singleton; }


} // namespace LilyPad
