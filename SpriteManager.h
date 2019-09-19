#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include "SpriteCreator.h"
#include <map>
#include <string>

using namespace std;
using namespace sf;

class SpriteManager
{
public:
	void ClearBase();
	void FillTextureBase(const string& TextureList);
	Sprite* GetSprite(const string& resourceName, float scale);

	static SpriteManager& GetSpriteManager()
	{
		static SpriteManager instance;
		return instance;
	}
private:
	map<string, Sprite*> Sprites;
	SpriteManager() {}
	SpriteCreator& Sprite_Creator = SpriteCreator::GetSpriteCreator();
};

