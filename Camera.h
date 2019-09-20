//GOVNO, PEREDELbIVAI

#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Camera
{
private:
	Vector2f Position;
public:
	void CalculatePosition(float x, float y, int sizex, int sizey);
	Vector2f GetPosition();
};