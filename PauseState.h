#pragma once
#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "Game.h"

using namespace sf;

class PauseState : public GameState
{
public:
	PauseState() {}
	PauseState(Game *game);

	virtual void HandleInput();
	virtual void Update(const float dt);
	virtual void Draw(const float dt);
private:
	void ResumeGame();
	void GoToMenu();
};