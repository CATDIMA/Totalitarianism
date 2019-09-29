#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"

using namespace sf;

class Control
{
public:
	void EnableKeyboard(Entity* ent);
	void EnableMouse();
};
