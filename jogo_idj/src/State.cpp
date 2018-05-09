#include "State.h"
#include <vector>
#define PI 3.14
#include <iostream>

State::State()
{
  quitRequested = false;
}

State::~State()
{
  objectArray.clear();
}

void State::LoadAssets()
{
  GameObject* background = new GameObject();
  GameObject* game_tile_map = new GameObject();
  GameObject* game_alien = new GameObject();

  CameraFollower* cameraFollower = new CameraFollower(*background);

	background->AddComponent(cameraFollower);

	Sprite* sprite_bg = new Sprite("assets/img/ocean.jpg", *background);

	background->AddComponent(sprite_bg);

  background->box.w = 1024;
	background->box.h = 600;
	background->box.x = 0;
	background->box.y = 0;

	objectArray.emplace_back(background);

  TileSet* set = new TileSet(64, 64, "assets/img/tileset.png", *game_tile_map);
	TileMap* map = new TileMap(*game_tile_map,"assets/map/tileMap.txt", set);

	game_tile_map->AddComponent(map);

  game_tile_map->box.x = 0;
	game_tile_map->box.y = 0;

	objectArray.emplace_back(game_tile_map);

  game_alien->box.x = 512;
	game_alien->box.y = 300;

	Alien* alien = new Alien(*game_alien, 5);

	game_alien->AddComponent(alien);

	objectArray.emplace_back(game_alien);

	//bg.Open("assets/img/ocean.jpg");
  music.Open("assets/audio/stageState.ogg");
  music.Play(-1);
}

void State::Update(float dt)
{
  InputManager& input = InputManager::GetInstance();

	if(input.QuitRequested() || input.IsKeyDown(SDLK_ESCAPE))
  {
    quitRequested = true;
  }

	/*
  if (input.KeyPress(SDLK_SPACE))
  {
    Vec2 objPos = Vec2(200, 0).GetRotated(-PI + PI*(rand() % 1001)/500.0) + Vec2(input.GetMouseX(), input.GetMouseY());
    AddObject((int)objPos.x, (int)objPos.y);
	}
  */

	Camera::Update(dt);

  int i;
	for (i=0; i<objectArray.size(); i++)
  {
		objectArray[i]->Update(dt);
	}

	for (i=0; i<objectArray.size(); i++)
  {
		if(objectArray[i]->IsDead())
    {
			objectArray.erase(objectArray.begin()+i);
		}
	}
}

void State::Render()
{
	//bg.Render(0, 0); // posições na tela em que ele vai renderizar.
  int i;
  for (i=0; i<objectArray.size(); i++)
  {
		objectArray[i]->Render();
	}
}

bool State::QuitRequested()
{
	return quitRequested;
}

void State::AddObject(int mouseX, int mouseY)
{
	GameObject* GO = new GameObject();

	Sprite* sprite_GO = new Sprite("assets/img/penguinface.png", *GO);

	GO->AddComponent(sprite_GO);

  GO->box.w = sprite_GO->GetWidth();
	GO->box.h = sprite_GO->GetHeight();
  GO->box.Centralize(mouseX - Camera::pos.x, mouseY - Camera::pos.y);

	Sound* sound_GO = new Sound(*GO, "assets/audio/boom.wav");

	GO->AddComponent(sound_GO);

	Face* face_GO = new Face(*GO);

  GO->AddComponent(face_GO);

	objectArray.emplace_back(GO);

  std::cout << "Criei GO!" << std::endl;
}

void State::Start()
{
  LoadAssets();

  int i;
  for(i=0;i<objectArray.size();i++)
  {
    objectArray[i]->Start();
  }

  started = true;
}

std::weak_ptr<GameObject> State::AddObject(GameObject* go)
{
	std::shared_ptr<GameObject> temp(go);

	objectArray.push_back(temp);

	if (started)
  {
		go->Start();
	}

	std::weak_ptr<GameObject> res(temp);

	return res;
}

std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go)
{
	std::weak_ptr<GameObject> res;

  int i;
	for(i=0; i < objectArray.size(); i++)
  {
		if(objectArray[i].get() == go)
    {
        res = objectArray[i];
    }
	}

	return res;
}
