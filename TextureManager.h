#pragma once
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class TextureManager
{
public:
	void ReadTexturesBase();
	Texture* GetTexture(const string& ResourceName);
	void ClearBase();
	void DeleteResource(const string& ResourceName);
	
	static TextureManager& GetManager()
	{
		static TextureManager instance;
		return instance;
	}
private:
	map<string, Texture*> Textures;

	TextureManager() 
	{
		ReadTexturesBase();
	}
};