#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "SpriteCreator.h"
#include "SpriteManager.h"

using namespace sf;

class MenuState : public GameState
{
public:
	MenuState(Game* game);
	MenuState() { }
	~MenuState();

	virtual void HandleInput();
	virtual void Update(const float& dt);
	virtual void Draw(const float& dt);
private:
	View view;
	Sprite MenuSprite;
	vector<Text> buttons;
	Font font;
	const unsigned int NUM_BUTTONS = 4;
	SpriteManager& Sprite_Manager = SpriteManager::GetSpriteManager();

	void LoadGame();
};