#ifndef Camera_h
#define Camera_h

#include "GameObject.h"
#include "Vec2.h"
#include "InputManager.h"

class Camera
{
public:
	static void Follow (GameObject* newFocus);
	static void Unfollow();
	static void Update(float dt);
	static Vec2 pos;
	static Vec2 speed;
	Camera();
	~Camera();

private:
	static GameObject* focus;
};

#endif
