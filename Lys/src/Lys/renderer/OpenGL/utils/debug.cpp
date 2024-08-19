#include "debug.hpp"

#include <GL/glew.h>

namespace Lys
{
	void draw_lines() { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }

	void draw_fill() { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }
} // namespace Lys