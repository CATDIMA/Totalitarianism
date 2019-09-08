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
			Resources.emplace(resource, path);
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
	string ErrorTexturePath = "images/Test.png";
	static Texture Error;
	Error.loadFromFile(ErrorTexturePath);

	auto itr = Resources.find(ResourceName);
	if (itr != Resources.end())
	{
		auto it = Textures.find(ResourceName);
		if (it == Textures.end())
		{
			Texture* texture = new Texture;
			texture->loadFromFile(itr->second);
			Textures.emplace(ResourceName, texture);
			return texture;
		}
		else
		{
			return it->second;
		}
		
	}
	else
	{
		cerr << "ERROR. Can't find " << ResourceName << endl;
		return &Error;
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


