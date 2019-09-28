#include "LoadingScreen.h"

void LoadingScreen::DrawLoadScreen(float scale, RenderWindow* w)
{
	texture.loadFromFile("images/Loading.png");
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	w->draw(sprite);
	w->display();
}
