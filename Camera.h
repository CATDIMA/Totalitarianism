//GOVNO, PEREDELbIVAI

#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;

class Camera
{
private:
	View view;
	int resX, resY;
	int sizeX = 100; 
	int sizeY = 100;
	Vector2f viewPosition;
public:
	Camera(int x, int y) : resX(x), resY(y)
	{
		view.setSize(Vector2f(static_cast<float>(resX), static_cast<float>(resY)));
	}
	~Camera() {}

	View* GetView();
	void SetView(Vector2f Position);
	void SetMapSize(int sizex, int sizey);
};