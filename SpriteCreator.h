#pragma once
#include "TextureManager.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class SpriteCreator
{
public:
	static SpriteCreator& GetSpriteCreator()
	{
		static SpriteCreator instance;
		return instance;
	}

	Sprite CreateSprite(const std::string& ResourceName, float scale);
private:
	SpriteCreator() { }
	Sprite sprite;
	TextureManager& texture_manager = TextureManager::GetManager();
};