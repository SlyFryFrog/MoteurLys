#include "camera.hpp"

#include "LilyPad/debug/logging.hpp"

void Camera::_ready()
{
	position = {0.0f, 0.0f, 10.0f};
	up = {0.0f, 1.0f, 0.0f};
	yaw = -90.0f;
	pitch = 0.0f;
	mouseSensitivity = 0.1f;
	zoom = 45.0f;
	constrainPitch = true;
	update_vectors();
}

void Camera::_process(double delta)
{
	float speed = 10.0f * (float)delta;

	if (Input::is_pressed(Key::W))
		position += speed * front;
	if (Input::is_pressed(Key::S))
		position -= speed * front;
	if (Input::is_pressed(Key::A))
		position -= speed * right;
	if (Input::is_pressed(Key::D))
		position += speed * right;

	update_vectors();
}

void Camera::_process_input(const InputHandler &event) {}