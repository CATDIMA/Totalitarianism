#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "entt.hpp"
#include <cstdint>

using namespace sf;
using namespace std;

MenuState::MenuState(Game* game)
{
	TextureManager& texture_manager = TextureManager::GetManager();
	MenuSprite.setTexture(*(texture_manager.GetTexture("MenuBackground")));
	
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
	cerr << 1 / dt << endl;
}

void MenuState::Draw(const float dt)
{
	game->window.draw(MenuSprite);
}

void MenuState::LoadGame()
{
	game->PushState(new PlayState(game));
	TextureManager& mManager = TextureManager::GetManager();	//Возможно пригодится при большом
	mManager.DeleteResource("MenuBackground");				//количестве ресурсов
}

MenuState::~MenuState()
{
	
}