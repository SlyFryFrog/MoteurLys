#include "input.hpp"


namespace LilyPad
{
	Input *Input::_singleton = nullptr;

	Input *Input::get_singleton()
	{
		if (!_singleton)
			_singleton = new Input();

		return _singleton;
	}

	Input::Input() { _singleton = this; }

	Input::~Input() { delete _singleton; }


} // namespace LilyPad
