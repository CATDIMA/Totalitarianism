#pragma once
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class TextureManager
{
public:
	void ReadTexturesBase(const string& TexturesList);
	Texture* GetTexture(const string& ResourceName);
	void ClearBase();
	void DeleteResource(const string& ResourceName);
	~TextureManager();
	
	static TextureManager& GetManager()
	{
		static TextureManager instance;
		return instance;
	}
private:
	map<string, Texture*> Textures;
	map<string, string> Resources;

	TextureManager() { }
};