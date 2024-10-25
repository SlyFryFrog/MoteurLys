#include <Lys/core/utils/paths.hpp>
#include <Lys/main/entry.hpp>

class DemoApp : public Lys::Application
{
public:
	DemoApp(const std::string &appName) { name = appName; }

	~DemoApp() = default;
};

/**
 * @brief Demo main function for an app using the Lys Engine
 *
 * @param argc
 * @param argv
 * @return Lys::Application* Instance of a Lys app. Can either extend the base app class or not.
 */
Lys::Application *Lys::create_application(int argc, char **argv)
{
	DemoApp *app = new DemoApp("Demo App");

	app->workingDir = Lys::get_root_directory();

	return app;
}
