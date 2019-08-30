#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

using namespace sf;

class GameState;

class Game
{
public:
	Game(int ResolutionX, int ResolutionY, bool VSync, bool Fullscreen);
	Game() {};
	~Game();

	void PushState(GameState *state);
	void PopState();

	GameState* CurrentState();

	void GameLoop();

	RenderWindow window;

private:
	std::vector<GameState*> states;
};