#include "Game.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;

Game::Game(int ResolutionX, int ResolutionY, bool VSync, bool Fullscreen)
{
	if (Fullscreen)
	{
		window.create(VideoMode(ResolutionX, ResolutionY), "Totalitarinism", Style::Fullscreen);
	}
	else
	{
		window.create(VideoMode(ResolutionX, ResolutionY), "Totalitarinism", Style::Close);
	}
	window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!states.empty())
	{
		PopState();
	}
}

void Game::PushState(GameState* state)
{
	states.push_back(state);
}

void Game::PopState()
{
	states.back();
	delete states.back();
	states.pop_back();
}

GameState* Game::CurrentState()
{
	if (states.empty())			//Вот этой вот штуковине нужен exception
	{
		return nullptr;
	}
	else
	{
		return states.back();
	}
}

void Game::GameLoop()
{
	Clock clock;

	while (window.isOpen())
	{
		Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Вот здесь exception на случай пустого стека

		CurrentState()->HandleEvent();
		CurrentState()->Update(dt);

		window.clear();

		CurrentState()->Draw(dt);

		window.display();
	}
}
