#include "core/rendering/window.hpp"

using namespace LilyPad;

int main()
{
    Window window;
    window.set_title("LilyPad Engine");
    window.set_dimensions(500, 500);
    
    window.initialize();

    return 0;
}