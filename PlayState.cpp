#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;

PlayState::PlayState(Game* game)
{
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

void PlayState::Update(const float dt)
{

}

void PlayState::Draw(const float dt)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(100, 100));
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Green);

	game->window.draw(rect);
}

void PlayState::PauseGame()
{

}
