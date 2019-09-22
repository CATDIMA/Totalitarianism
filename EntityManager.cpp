#include "EntityManager.h"
#include <iostream>

void EntityManager::AddEntity(Entity* ent)
{
	Entities.push_back(ent);
}

void EntityManager::Refresh()
{
	cerr << Entities.size() << endl;
}

Entity* EntityManager::GetEntityList()
{
	if (!Entities.empty())
		for (auto itr : Entities)
		{
			return itr;
		}
	else
		return nullptr;
}
