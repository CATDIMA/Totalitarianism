#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace std;
using namespace sf;

const float SCALE = 30.0f;
const float DEG = 57.29577f;
int ResolutionX = 640;		//А потом это рефакторить что-ли?
int ResolutionY = 480;		//
bool Vsync = true;			//А, ну да
bool Fullscreen = false;	//БЛИН

b2Vec2 NoGravity(0.0f, 0.0f);
b2World World(NoGravity);

int main()
{
	Game game(ResolutionX, ResolutionY, Vsync, Fullscreen);

	game.GameLoop();

	return 0;
}