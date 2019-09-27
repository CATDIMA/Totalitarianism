#pragma once
#include "SFML/Graphics.hpp"
#include "SpriteCreator.h"
#include "TextureManager.h"
#include "Entity.h"
#include "Box2D/Box2D.h"
#include "Game.h"
#include <string>

using namespace sf;

class Player : public Entity
{
public:
	Player(float xpos, float ypos);

	Sprite GetSprite();

	void Draw(RenderWindow *window) override;
	void Update() override;

private:
	TextureManager& Texture_Manager = TextureManager::GetManager();		//Костыль	
	float Width, Height;
	std::string tag = "Player";
};

