#include "camera.hpp"

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

void Camera::_process(double delta) {}

void Camera::_process_input(const Input &events) 
{
	for (auto event : events.get_keys_pressed())
	{
		
	}
}