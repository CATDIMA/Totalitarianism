#pragma once
#include "Game.h"
#include "Box2D/Box2D.h"

class GameState
{
public:
	Game *game = nullptr;

	virtual void Update(const float& dt) = 0;
	virtual void Draw(const float& dt) = 0;
	virtual void HandleInput() = 0;

	virtual ~GameState() {}
};