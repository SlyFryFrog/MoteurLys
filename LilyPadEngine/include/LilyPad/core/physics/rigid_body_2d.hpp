#pragma once

#include "LilyPad/core/math/vector2.hpp"


namespace LilyPad
{
	class RigidBody2D
	{
	public:
		RigidBody2D();

		virtual void physics_process(float delta) {}

		void apply_force(const Vector2 &force);

		bool is_colliding();

		bool is_colliding(const RigidBody2D &a, const RigidBody2D &b);

	private:
		Vector2 _acceleration;
		Vector2 _velocity;
		Point2 _position;
		float _mass;
		bool _freeze;
		bool _lock_rotation;
	};
} // namespace LilyPad