#include "TextureManager.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
#include <fstream>
#include <iostream>

void TextureManager::ReadTexturesBase()
{
	ifstream input("images/textures.txt");
	string path;
	string resource;

	if (input.is_open())
	{
		cerr << "images/textures.txt available" << endl;
		while (!input.eof())
		{
			input >> resource >> path;
			Texture* texture = new Texture;
			texture->loadFromFile(path);
			Textures.emplace(resource, texture);
		}
		input.close();
	}
	else
	{
		cerr << "ERROR. Failed to load images/textures.txt" << endl;
	}
}

Texture* TextureManager::GetTexture(const string& ResourceName)
{
	auto itr = Textures.find(ResourceName);
	if (itr != Textures.end())
	{
		return itr->second;
	}
	else
	{
		cerr << "ERROR. Can't find " << ResourceName << endl;
		return nullptr;
	}
}

void TextureManager::ClearBase()
{
	Textures.clear();
}

void TextureManager::DeleteResource(const string& ResourceName)
{
	Textures.erase(ResourceName);
}


