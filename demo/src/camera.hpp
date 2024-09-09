#include <lys.hpp>

using namespace Lys;

class Camera : public Camera3D
{
public:
	void _ready() override;
	void _process(double delta) override;
	void _process_input(const InputEventCore &event) override;

private:
	float _velocity;
	bool drawLines = false;
};