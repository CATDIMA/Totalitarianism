#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "States.h"
#include "TextureManager.h"

using namespace std;
using namespace sf;

const float SCALE = 30.0f;
const float DEG = 57.29577f;
int ResolutionX = 1024;		//А потом это рефакторить что-ли?
int ResolutionY = 720;		//
bool Vsync = true;			//А, ну да
bool Fullscreen = false;	//БЛИН
b2Vec2 Gravity(0.0f, 0.0f);
b2World World(Gravity); 
float GlobalScale = 1;

int main()
{
	
	Game game(ResolutionX, ResolutionY, Vsync, Fullscreen);

	game.PushState(new MenuState(&game));

	game.GameLoop();

	return 0;
}