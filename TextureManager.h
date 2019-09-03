#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceManager.h"
#include <string>

using namespace sf;

string TexturePathTxt = "textures.txt";

class TextureManager : public ResourceManager<TextureManager, Texture>
{
	TextureManager() : ResourceManager(TexturePathTxt) { }

	Texture* Load(const string& FileName)
	{
		Texture* texture = new Texture();
		
		if (!texture->loadFromFile(FileName))
		{
			delete texture;
			texture = nullptr;
			cout << "FAILED TO LOAD TEXTURE " << FileName << endl;
		}

		return texture;
	}
};