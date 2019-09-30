#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "States.h"
#include "EntityManager.h"
#include "WorldContainer.h"

using namespace std;
using namespace sf;

int ResolutionX = 1200;		//А потом это рефакторить что-ли?
int ResolutionY = 720;		//
bool Vsync = true;			//А, ну да
bool Fullscreen = false;	//БЛИН
float GlobalScale = 1;
b2Vec2 Gravity(0.0f, 0.0f);
b2World World(Gravity);
WorldContainer& Container = WorldContainer::GetWorldContainer();

int main()
{
	Game game(ResolutionX, ResolutionY, Vsync, Fullscreen);
	Container.SetWorld(&World);

	game.PushState(new MenuState(&game));

	game.GameLoop();

	return 0;
}