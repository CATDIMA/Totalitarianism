#pragma once
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class SpriteManager;
class SpriteCreator;

class TextureManager
{
public:
	Texture* GetTexture(const string& ResourceName);
	
	~TextureManager();
	
	static TextureManager& GetManager()
	{
		static TextureManager instance;
		return instance;
	}
private:
	map<string, Texture*> Textures;
	map<string, string> Resources;

	void ReadTexturesBase(const string& TexturesList);
	void ClearBase();

	TextureManager() { }

	friend SpriteManager;
	friend SpriteCreator;
};