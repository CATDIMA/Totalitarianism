#pragma once
#include "TextureManager.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SpriteCreator
{
public:
	static SpriteCreator& GetSpriteCreator()
	{
		SpriteCreator instance;
		return instance;
	}

	Sprite CreateSprite(Texture& texture, float& scale);
private:
	SpriteCreator() { }
	Sprite sprite;
};