#pragma once
#include "SFML/Graphics.hpp"
#include "Entity.h"

using namespace sf;

class Animation
{
public:
	void Animate(Entity *entity, float dt);
private:
	IntRect rect_;
	int frames_;
	int rows_;
	float currentFrame_ = 0.0;
	int frameSpeed_;
	State state_;
};

