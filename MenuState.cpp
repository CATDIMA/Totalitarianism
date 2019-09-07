#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

MenuState::MenuState(Game* game)
{
	TextureManager& texture_manager = TextureManager::GetManager();
	MenuSprite.setTexture(*(texture_manager.GetTexture("MenuBackground")));

	Text text;
	font.loadFromFile("fonts/PixelFont.ttf");
	text.setFont(font);
	text.setPosition(100.0f, 200.0f);
	text.setCharacterSize(48);
	text.setFillColor(Color::White);

	for (unsigned int i = 0; i < NUM_BUTTONS; i++)
	{
		buttons.push_back(text);
		buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
	}

	buttons[0].setString("New");
	buttons[1].setString("Load");
	buttons[2].setString("Options");
	buttons[3].setString("Quit");

	this->game = game;
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

void MenuState::Update(const float dt)
{

}

void MenuState::Draw(const float dt)
{
	game->window.draw(MenuSprite);
	for (Text x : buttons)
	{
		game->window.draw(x);
	}
}

void MenuState::LoadGame()
{
	game->PushState(new PlayState(game));
}