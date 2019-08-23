#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

const float SCALE = 30.0f;
const float DEG = 57.29577f;
int ResolutionX = 640;
int ResolutionY = 480;
bool IsRunning = true;
bool Vsync = true;

b2Vec2 NoGravity(0.0f, 0.0f);
b2World World(NoGravity);

int main()
{
	RenderWindow window(VideoMode(ResolutionX, ResolutionY), "Totalitarianism", Style::Close);

	while (IsRunning)
	{
		//ьн?
	}

	return 0;
}