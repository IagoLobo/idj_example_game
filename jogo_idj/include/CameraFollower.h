#ifndef CameraFollower_h
#define CameraFollower_h

#include "Component.h"
#include "Camera.h"

class CameraFollower : public Component
{
public:
	CameraFollower(GameObject& go);
	~CameraFollower();
	void Update(float dt);
	void Render();
	bool Is(std::string type);
};

#endif
