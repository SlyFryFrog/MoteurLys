#pragma once

#include "LilyPad/core/math/vector3.hpp"
#include "LilyPad/scene/nodes/3d/node_3d.hpp"

namespace LilyPad
{
	class Camera3D : Node3D
	{
	public:
		fp_type Yaw;
		fp_type Pitch;

		void look_at(Position3 point);

	private:
	};
} // namespace LilyPad