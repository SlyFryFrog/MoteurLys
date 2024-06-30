#pragma once

#include "LilyPad/renderer/OpenGL/vertex.hpp"

namespace LilyPad
{
	class Bind
	{
	public:
        Bind();
    
        void buffer_data(Vertex data);

        void buffer_data(VertexC data);
    private:
        unsigned int VAO;   // Vertex array
        unsigned int VBO;   // Data
        unsigned int EBO;   // Indices
	};
} // namespace LilyPad
