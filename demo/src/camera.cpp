#include "camera.hpp"

void Camera::_ready()
{
	position = {0, 0, 10};
	up = {0.0f, 1.0f, 0.0f};
    yaw = -90.0f;
    pitch = 0.0f;
	Position3 point = {0.0f, 0.0f, 0.0f};
	front = (point - position).normalize();
}

void Camera::_process(double delta) {}

void Camera::_process_input() {}