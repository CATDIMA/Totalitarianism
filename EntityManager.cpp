#include "EntityManager.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

void EntityManager::AddEntity(EntitiesENUM e, float xpos, float ypos)
{
	switch (e)
	{
	case EntitiesENUM::PLAYER:
	{
		Player* ent = new Player(xpos, ypos);
		Entities.push_back(ent);
		break;
	}
	default:
		break;
	}
}

void EntityManager::Refresh()
{
	cerr << Entities.size() << endl;
}

void EntityManager::EntityDraw(RenderWindow* w)
{
	if (!(Entities.empty()))
	{
		for (auto itr : Entities)
		{
			itr->Draw(w);
		}
	}
}

int EntityManager::ReturnEntitiesSize()
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
		return nullptr;
}

