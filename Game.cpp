#include "Game.h"
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

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
	states.emplace(state);
}

void Game::PopState()
{
	delete states.top();
	states.pop();
}

GameState* Game::CurrentState()
{
	if (states.empty())			//Вот этой вот штуковине нужен exception
	{
		return nullptr;
	}
	else
	{
		return states.top();
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

		CurrentState()->HandleInput();
		CurrentState()->Update(dt);

		window.clear();

		CurrentState()->Draw(dt);

		window.display();
	}
}
