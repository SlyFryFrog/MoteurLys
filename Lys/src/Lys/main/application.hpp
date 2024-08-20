#pragma once

namespace Lys
{
	class Application
	{
		static Application *_singleton;

	public:
		Application();
        
		static Application *get_singleton();

        void create();

	private:
	};
} // namespace Lys
