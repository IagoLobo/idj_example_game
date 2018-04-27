#include "Camera.h"

GameObject* Camera::focus = nullptr;
Vec2 Camera::pos(0,0);
Vec2 Camera::speed;

void Camera::Follow(GameObject* newFocus)
{
	focus = newFocus;
}

void Camera::Unfollow()
{
	focus = nullptr;
}

void Camera::Update(float dt)
{
	InputManager& input = InputManager::GetInstance();

	speed.x = 0;
	speed.y = 0;

	dt = dt * 200;

	if (focus != nullptr)
	{
		pos = focus->box.GetCenter() - Vec2(512, 300);
	}
	else
	{
		if(input.IsKeyDown(SDLK_LEFT))
		{
			speed.x += dt;
		}

		if(input.IsKeyDown(SDLK_RIGHT))
		{
			speed.x -= dt;
		}

		if(input.IsKeyDown(SDLK_UP))
		{
			speed.y += dt;
		}

		if(input.IsKeyDown(SDLK_DOWN))
		{
			speed.y -= dt;
		}

		pos.x += speed.x;
		pos.y += speed.y;
	}
}

Camera::Camera()
{

}

Camera::~Camera()
{

}
