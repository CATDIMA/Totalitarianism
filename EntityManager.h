#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entity.h"
#include <vector>

using namespace sf;
using namespace std;

class EntityManager
{
public:
	void AddEntity(Entity* ent);
	void Refresh();
	Entity* GetEntityList();

	static EntityManager& GetEntityManager()
	{
		static EntityManager instance;
		return instance;
	}
private:
	vector<Entity*> Entities;
	static b2World* World;

	EntityManager() {}
};

