#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include "WorldContainer.h"

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

b2Body* EntityManager::SearchBodyByID(int id)
{
	b2Body* body = nullptr;
	for (b2Body* itr = worldContainer.GetWorld()->GetBodyList(); itr != 0; itr = itr->GetNext())
	{
		if (itr->GetUserData() == (void*)(id))
		{
			body = itr;
		}
	}
	return body;
}

Entity* EntityManager::SearchEntityByTag(const char* tag)
{
	for (auto itr : Entities)
	{
		if (itr->GetTag() == tag)
		{
			return itr;
		}
		else return nullptr;
	}
}
