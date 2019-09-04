#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class MenuState : public GameState
{
public:
	MenuState(Game* game);
	MenuState() { }

	virtual void HandleInput();
	virtual void Update(const float dt);
	virtual void Draw(const float dt);

private:
	View view;
	Sprite MenuSprite;

	void LoadGame();
};