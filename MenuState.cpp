#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "LoadingScreen.h"
#include <cstdint>

using namespace sf;
using namespace std;

MenuState::MenuState(Game* game)
{
	this->game = game;

	LoadingScreen Loading;
	Loading.DrawLoadScreen(0.55f, &this->game->window);
	IntRect MenuRect(0, 0, 1200, 675);
	Sprite_Manager.FillTextureBase("menu");
	MenuSprite = *(Sprite_Manager.GetSprite("MenuBackground", 1.0f, MenuRect));
}

void MenuState::HandleInput()
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
			if(event.key.code == Keyboard::Escape)
			{
				this->game->window.close();
			}
			else if (event.key.code == Keyboard::Enter)
			{
				LoadGame();
			}
			break;
		}
	}
}

void MenuState::Update(const float& dt)
{
	cerr << 1 / dt << endl;
}

void MenuState::Draw(const float& dt)
{
	game->window.draw(MenuSprite);
}

void MenuState::LoadGame()
{
	this->game->window.clear();
	Sprite_Manager.ClearBase();
	game->PushState(new PlayState(game));							
}

MenuState::~MenuState()
{
	Sprite_Manager.ClearBase();
}