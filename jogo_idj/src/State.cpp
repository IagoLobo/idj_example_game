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

	Sprite* sprite_bg = new Sprite("assets/img/ocean.jpg", *background);

	background->AddComponent(sprite_bg);

	//enemy->box.x = mouseX;
	//enemy->box.y = mouseY;

  background->box.w = 1024;
	background->box.h = 600;
	background->box.x = 0;
	background->box.y = 0;

	objectArray.emplace_back(background);

	//bg.Open("assets/img/ocean.jpg");
  music.Open("assets/audio/stageState.ogg");
  music.Play(-1);
}

void State::Update(float dt)
{
  Input();
  int i;
	for (i=0; i<objectArray.size(); i++)
  {
		objectArray[i]->Update(0);
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

void State::Input()
{
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event))
  {
		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT)
    {
			quitRequested = true;
		}

		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN)
    {
			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i)
      {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.Contains((float)mouseX, (float)mouseY))
        {
					Face* face = (Face*)go->GetComponent( "face" );
					if (nullptr != face)
          {
            std::cout << "Cliquei dentro do penguin!" << std::endl;
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}

		if(event.type == SDL_KEYDOWN )
    {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE )
      {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else
      {
				Vec2 objPos = Vec2(200, 0).GetRotated(-PI + PI*(rand() % 1001)/500.0 ) + Vec2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int mouseX, int mouseY)
{
	GameObject* GO = new GameObject();

	Sprite* sprite_GO = new Sprite("assets/img/penguinface.png", *GO);

	GO->AddComponent(sprite_GO);

	//enemy->box.x = mouseX;
	//enemy->box.y = mouseY;

  GO->box.w = sprite_GO->GetWidth();
	GO->box.h = sprite_GO->GetHeight();
	GO->box.x = mouseX - (GO->box.w/2);
	GO->box.y = mouseY - (GO->box.h/2);

	Sound* sound_GO = new Sound(*GO, "assets/audio/boom.wav");

	GO->AddComponent(sound_GO);

	Face* face_GO = new Face(*GO);

  GO->AddComponent(face_GO);

	objectArray.emplace_back(GO);

  std::cout << "Criei GO!" << std::endl;
}
