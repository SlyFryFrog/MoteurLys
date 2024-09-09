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

void Camera::_process(double delta)
{
	float speed = 10.0f * (float)delta;

	if (InputManager::is_pressed(Key::W))
		position += speed * Vector3(front.x, 0.0f, front.z);
	// if (Input::is_pressed(Key::S))
	// 	position -= speed * Vector3(front.x, 0.0f, front.z);
	// if (Input::is_pressed(Key::A))
	// 	position -= speed * Vector3(right.x, 0.0f, right.z);
	// if (Input::is_pressed(Key::D))
	// 	position += speed * Vector3(right.x, 0.0f, right.z);
	// if (Input::is_pressed(Key::SPACE))
	// 	position.y += speed;
	// if (Input::is_pressed(Key::SHIFT))
	// 	position.y -= speed;

	update_vectors();
}

void Camera::_process_input(const InputEventCore &event)
{
	if (const MouseMotionEvent *motionEvent = dynamic_cast<const MouseMotionEvent *>(&event))
	{

	}
	// if (const InputKeyEvent *keyEvent = dynamic_cast<const InputKeyEvent *>(&event))
	// {
	// 	if (keyEvent->get_key() == Key::F3 && keyEvent->is_pressed() && !keyEvent->is_repeat())
	// 	{
	// 		if (drawLines)
	// 			draw_fill();
	// 		else
	// 			draw_lines();

	// 		drawLines = !drawLines;
	// 	}
	// 	if (event.is_just_pressed() && event.get_key() == Key::ESCAPE)
	// 	{
	// 		Window::terminate();
	// 	}
	// }

	// if (const InputMouseEvent *mouseEvent = dynamic_cast<const InputMouseEvent *>(&event))
	// {
		
	// }
}