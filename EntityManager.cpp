#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

void EntityManager::Refresh()
{
	cerr << Entities.size() << endl;
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
