#include "TextureManager.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
#include <fstream>
#include <iostream>

void TextureManager::ReadTexturesBase(const string& TexturesList)
{
	string Input = "images/" + TexturesList + ".txt";
	ifstream input(Input);
	string path;
	string resource;

	if (input.is_open())
	{
		cerr << Input << " available" << endl;
		while (!input.eof())
		{
			input >> resource >> path;
			Resources.emplace(resource, path);
		}
		input.close();
	}
	else
	{
		cerr << "ERROR. Failed to load " << TexturesList << endl;
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
	if (Textures.size() != 0)
	{
		for (auto itr : Textures)
		{
			delete itr.second;
		}
	}
	Textures.clear();
	if (Textures.size() == 0)
	{
		cerr << "TEXTURE BASE CLEARED" << endl;
	}
	Resources.clear();
}

TextureManager::~TextureManager()
{
	Textures.clear();
}