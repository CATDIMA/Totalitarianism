#pragma once
#include "Game.h"

class GameState
{
public:
	virtual void Update(const float dt) = 0;
	virtual void Draw(const float dt) = 0;
	virtual void HandleEvent() = 0;
};

