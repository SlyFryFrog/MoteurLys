#pragma once

#include "Lys/scene/nodes/2d/sprite_2d.hpp"

using namespace Lys;

class Player : public Sprite2D
{
public:
	void _process_input(const InputHandler &event) override;
};