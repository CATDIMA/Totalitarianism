#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entity.h"
#include "Animation.h"
#include <vector>

using namespace sf;
using namespace std;

class EntityManager
{
public:
	template <class T>
	void AddEntity(float xpos, float ypos, float scale)
	{
		T* ent = new T(xpos, ypos, scale);
		Entities.emplace_back(ent);
	}

	void Refresh();
	void EntitiesDraw(RenderWindow* w, float dt);
	void ClearBase();
	size_t GetEntitiesSize();
	Entity* GetEntityList();
	b2Body* SearchBodyByID(int id);
	Entity* SearchEntityByTag(const char* tag);

	static EntityManager& GetEntityManager()
	{
		static EntityManager instance;
		return instance;
	}
private:
	vector<Entity*> Entities;
	WorldContainer& worldContainer = WorldContainer::GetWorldContainer();
	SpriteManager& spriteManager = SpriteManager::GetSpriteManager();
	Animation Animator;

	EntityManager() { }
};

