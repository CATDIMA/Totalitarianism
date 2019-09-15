#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class PlayState : public GameState
{
public:
	PlayState() {}
	PlayState(Game* game);

	virtual void HandleInput();
	virtual void Update(const float& dt);
	virtual void Draw(const float& dt);
private:
	void PauseGame();
};