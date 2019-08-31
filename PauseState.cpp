#include "PauseState.h"
#include "GameState.h"
#include "PlayState.h"
#include "MenuState.h"
#include "SFML/Graphics.hpp"

using namespace sf;

PauseState::PauseState(Game* game)
{
	this->game = game;
}

void PauseState::HandleInput()
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
			{
				GoToMenu();
			}
			else if (event.key.code == Keyboard::Enter)
			{
				ResumeGame();
			}
			break;
		}
	}
}

void PauseState::Update(const float dt)
{

}

void PauseState::Draw(const float dt)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(200, 200));
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::White);

	game->window.draw(rect);
}

void PauseState::ResumeGame()
{
	game->PushState(new PlayState(game));
}

void PauseState::GoToMenu()
{
	game->PushState(new MenuState(game));
}