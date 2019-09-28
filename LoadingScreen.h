#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class LoadingScreen
{
public:
	void DrawLoadScreen(float scale, RenderWindow* w);
private:
	Texture texture;
	Sprite sprite;
};

