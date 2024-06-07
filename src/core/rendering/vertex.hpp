#include <glm/glm.hpp>

namespace LilyPad
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec2 textureCoord;
    };

    struct VertexC : Vertex
    {
        glm::vec3 colorCoord;
    };
}