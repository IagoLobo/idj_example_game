#include "InputManager.h"

void InputManager::Update()
{
	SDL_Event event;
	SDL_GetMouseState(&mouseX, &mouseY);
	quitRequested = false;
	updateCounter++;

	while (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			quitRequested = true;
		}

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
			mouseState[event.button.button] = true;
			mouseUpdate[event.button.button] = updateCounter;
		}

		if(event.type == SDL_MOUSEBUTTONUP)
		{
			mouseState[event.button.button] = false;
			mouseUpdate[event.button.button] = updateCounter;
		}

		if(event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
				keyState[event.key.keysym.sym] = true;
				keyUpdate[event.key.keysym.sym] = updateCounter;
		}

		if(event.type == SDL_KEYUP)
		{
			keyState[event.key.keysym.sym] = false;
			keyUpdate[event.key.keysym.sym] = updateCounter;
		}
	}
}

bool InputManager::KeyPress (int key)
{
	if(updateCounter == keyUpdate[key] && keyState[key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::KeyRelease (int key)
{
	if(updateCounter == keyUpdate[key] && !keyState[key])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsKeyDown (int key)
{
	return keyState[key];
}

bool InputManager::MousePress (int button)
{
	if(updateCounter == mouseUpdate[button] && mouseState[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::MouseRelease (int button)
{
	if(updateCounter == mouseUpdate[button] && !mouseState[button])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::IsMouseDown (int button)
{
	return mouseState[button];
}

int InputManager::GetMouseX()
{
	return mouseX;
}

int InputManager::GetMouseY()
{
	return mouseY;
}

bool InputManager::QuitRequested()
{
	return quitRequested;
}

InputManager& InputManager::GetInstance()
{
	static InputManager inputManagerInstance;
	return inputManagerInstance;
}

InputManager::InputManager()
{
	bool mouseState[6] = {0};
	int mouseUpdate[6] = {0};
}

InputManager::~InputManager()
{

}
