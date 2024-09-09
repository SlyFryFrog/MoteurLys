#pragma once

#ifdef __linux__

#include "Lys/debug/logging.hpp"
#include "Lys/main/application.hpp"

extern Lys::Application *Lys::create_application(int argc, char **argv);

int main(int argc, char **argv)
{
	auto app = Lys::create_application(argc, argv);

	if (!app->init())
	{
		LYS_CRITICAL("Failed to initialize the Lys Engine.");
		app->shutdown();
		return -1;
	}

	app->run();

	delete app;

	return 0;
}

#else
#error Only linux is supported.
#endif
