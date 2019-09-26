#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entity.h"
#include <vector>

using namespace sf;
using namespace std;

enum EntitiesENUM
{
	PLAYER
};

class EntityManager
{
public:
	void AddEntity(EntitiesENUM p, float xpos, float ypos);
	void Refresh();
	void EntityDraw(RenderWindow* w);
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

