#include "SpriteManager.h"
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "SpriteCreator.h"
#include <map>
#include <string>
#include <iostream>

void SpriteManager::ClearBase()
{
	if (Sprites.size() != 0)
	{
		for (auto itr : Sprites)
		{
			delete itr.second;
		}
	}
	Sprites.clear();
	if (Sprites.size() == 0)
	{
		cerr << "SPRITE BASE HAS BEEN CLEARED" << endl;
	}
	Sprite_Creator.texture_manager.ClearBase();
}

void SpriteManager::FillTextureBase(const string& TextureList)
{
	Sprite_Creator.texture_manager.ReadTexturesBase(TextureList);
}

Sprite* SpriteManager::GetSprite(const string& ResourceName, float scale)
{
	auto itr = Sprites.find(ResourceName);
	if (itr != Sprites.end())
	{
		return itr->second;
	}
	else
	{
		Sprite* s = new Sprite;
		*s = Sprite_Creator.CreateSprite(ResourceName, scale);
		Sprites.emplace(ResourceName, s);
		return s;
	}
}
