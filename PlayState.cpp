#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "EntityManager.h"
#include "LoadingScreen.h"
#include "Control.h"

using namespace sf;

Control control;

PlayState::PlayState(Game* game)
{
	this->game = game;
	
	LoadingScreen Loading;
	Loading.DrawLoadScreen(0.55f, &this->game->window);
	Level.LoadFromFile("maps/main.tmx");
	Sprite_Manager.FillTextureBase("game");
	Level.Draw(this->game->window);
	Entity_Manager.AddEntity<Player>(120.0f, 100.0f, 2.0f);
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
	worldContainer.GetWorld()->Step(1 / 60.0f, 8, 3);
	control.EnableKeyboard(Entity_Manager.SearchEntityByTag("Player"));
}

void PlayState::Draw(const float& dt)
{
	Level.Draw(this->game->window);
	Entity_Manager.EntitiesDraw(&(this->game->window));
}

void PlayState::PauseGame()
{
	Entity_Manager.ClearBase();
	Sprite_Manager.ClearBase();
	this->game->window.clear();
	game->PushState(new PauseState(game));
}
