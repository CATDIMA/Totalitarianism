#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Entity.h"

using namespace sf;

PlayState::PlayState(Game* game)
{
	this->game = game;
	//Player player(40.0f, 40.0f);
	Entity_Manager.AddEntity(&(Player(40.0f, 40.0f)));
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
}

void PlayState::Draw(const float& dt)
{
	Entity_Manager.GetEntityList()->Draw(&(this->game->window));
}

void PlayState::PauseGame()
{
	game->PushState(new PauseState(game));
}
