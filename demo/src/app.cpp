#include <Lys/core/utils/paths.hpp>
#include <Lys/main/entry.hpp>
#include <lys.hpp>

class DemoApp : public Lys::Application
{
public:
	DemoApp() {}

	~DemoApp() = default;
};

Lys::Application *Lys::create_application(int argc, char **argv)
{
	DemoApp *app = new DemoApp();

	app->name = "Demo";
	app->workingDir = Lys::get_root_directory();

	return app;
}