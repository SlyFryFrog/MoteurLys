#include "LilyPad/scene/nodes/3d/camera_3d.hpp"

using namespace LilyPad;

class Camera : public Camera3D
{
public:
    void _ready() override;
    void _process(double delta) override;
    void _process_input() override;
private:
    float _velocity;
};