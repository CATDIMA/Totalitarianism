#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "EntityManager.h"

using namespace sf;

class Control
{
public:
	void EnableKeyboard(Entity* ent);
	void EnableMouse();
private:
	EntityManager& entityManager = EntityManager::GetEntityManager();
};
