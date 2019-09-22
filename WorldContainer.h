#pragma once
#include "Box2D/Box2D.h"

class WorldContainer
{
public:

	static WorldContainer& GetWorldContainer()
	{
		static WorldContainer instance;
		return instance;
	}

	void SetWorld(b2World* w)
	{
		world = w;
	}
	b2World* GetWorld()
	{
		return world;
	}
private:
	WorldContainer() {}
	b2World* world = nullptr;
};
