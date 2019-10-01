//GOVNO, PEREDELbIVAI

#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Camera
{
private:
	View view;
	int resX, resY;
	Vector2f viewPosition;
public:
	Camera(int x, int y) : resX(x), resY(y) 
	{
		view.setSize(Vector2f(resX, resY));
	}

	View* GetView();
	void SetView(Vector2f Position);
};