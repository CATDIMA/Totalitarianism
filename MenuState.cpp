#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

MenuState::MenuState(Game* game)
{
	this->game = game;
}

void MenuState::HandleInput()
{
	Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			game->window.close();
			break;
		case Event::KeyPressed:
			if(event.key.code == Keyboard::Escape)
			{
				game->window.close();
			}
			else if (event.key.code == Keyboard::Enter)
			{
				LoadGame();
			}
			break;
		}
	}
}

void MenuState::Update(const float dt)
{

}

void MenuState::Draw(const float dt)
{

}

void MenuState::LoadGame()
{
	game->PushState(new PlayState(game));
}