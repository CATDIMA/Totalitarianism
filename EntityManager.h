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
	template <class T>
	void AddEntity(float xpos, float ypos)
	{
		T* ent = new T(xpos, ypos);
		Entities.emplace_back(ent);
	}

	void Refresh();
	void EntitiesDraw(RenderWindow* w);
	int GetEntitiesSize();
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

