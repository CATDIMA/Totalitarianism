#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "GameState.h"

using namespace std;
using namespace sf;

const float SCALE = 30.0f;
const float DEG = 57.29577f;
int ResolutionX = 640;
int ResolutionY = 480;
bool Vsync = true;

b2Vec2 NoGravity(0.0f, 0.0f);
b2World World(NoGravity);

int main()
{
	RenderWindow window(VideoMode(ResolutionX, ResolutionY), "Totalitarianism", Style::Close);

	GameEngine game;

	//game.Init();
	//game.ChangeState(arg);
	
	while (game.Running())	//main loop
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.Cleanup();

	return 0;
}