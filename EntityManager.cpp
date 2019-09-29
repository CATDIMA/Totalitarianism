#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include "Player.h"

using namespace std;

void EntityManager::Refresh()
{
	if (!Entities.size())
	{
		for (auto itr : Entities)
		{
			itr->Update();
		}
	}
}

void EntityManager::EntitiesDraw(RenderWindow* w)
{
	if (!Entities.empty())
	{
		for (auto itr : Entities)
		{
			itr->Draw(w);
		}
	}
}

void EntityManager::ClearBase()
{
	while (!Entities.empty())
	{
		for (auto itr : Entities)
		{
			delete itr;
		}
		Entities.clear();
	}
	if (Entities.empty()) cerr << "Entities destroyed" << endl;
}

size_t EntityManager::GetEntitiesSize()
{
	return Entities.size();
}

Entity* EntityManager::GetEntityList()
{
	if (!Entities.empty())
	{
		for (auto itr : Entities)
		{
			return itr;
		}
	}
	else
	{
		return nullptr;
	}
}

Entity* EntityManager::SearchEntityByTag(string tag)
{
	for (auto i : Entities)
	{
		if (i->GetTag() == tag)
			return i;
		else return nullptr;
	}
}
