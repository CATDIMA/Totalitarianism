#pragma once
#include "SFML/Graphics.hpp"
#include "SpriteCreator.h"
#include "Entity.h"
#include "Box2D/Box2D.h"
#include "Game.h"
#include "Animation.h"
#include <string>

using namespace sf;

class Player : public Entity
{
public:
	Player(float xpos, float ypos, float scale);

	Sprite GetSprite();

	void Draw(RenderWindow *window, float dt) override;
	void Update() override;

private:
	SpriteManager& Sprite_Manager = SpriteManager::GetSpriteManager();
	Animation Animator;
};

