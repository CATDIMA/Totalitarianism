#pragma once
#include "GameState.h"
#include "Player.h"

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
	Entity e;
};