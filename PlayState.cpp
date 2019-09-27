#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "EntityManager.h"

using namespace sf;

PlayState::PlayState(Game* game)
{
	Sprite_Manager.FillTextureBase("game");
	Entity_Manager.AddEntity<Player>(40.0f, 40.0f, 4.0f);

	this->game = game;
}

void PlayState::HandleInput()
{
	Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			this->game->window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
				PauseGame();
			break;
		}
	}
}

void PlayState::Update(const float& dt)
{
	cerr << 1 / dt << endl;
	//Обновляем энтити
}

void PlayState::Draw(const float& dt)
{
	Entity_Manager.EntitiesDraw(&(this->game->window));
}

void PlayState::PauseGame()
{
	Entity_Manager.ClearBase();
	Sprite_Manager.ClearBase();
	game->PushState(new PauseState(game));
}
