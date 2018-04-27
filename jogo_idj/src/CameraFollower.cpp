#include "CameraFollower.h"

CameraFollower::CameraFollower(GameObject& go) : Component(go)
{

}

CameraFollower::~CameraFollower()
{

}

void CameraFollower::Update(float dt)
{
	associated.box.x = -Camera::pos.x;
	associated.box.y = -Camera::pos.y;
}

void CameraFollower::Render()
{

}

bool CameraFollower::Is(std::string type)
{
	if(type == "cameraFollower")
	{
		return true;
	}
	else
	{
		return false;
	}
}
