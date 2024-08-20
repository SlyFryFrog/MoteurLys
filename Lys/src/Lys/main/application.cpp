#include "application.hpp"

namespace Lys
{
	Application *Application::_singleton = nullptr;
	Application *Application::get_singleton() { return _singleton; }
} // namespace Lys
