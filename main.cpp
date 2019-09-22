#include <iostream>
#include <string>
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "States.h"
#include "Entity.h"

using namespace std;
using namespace sf;

const float SCALE = 30.0f;
const float DEG = 57.29577f;
int ResolutionX = 1024;		//� ����� ��� ����������� ���-��?
int ResolutionY = 720;		//
bool Vsync = true;			//�, �� ��
bool Fullscreen = false;	//����
float GlobalScale = 1;
b2Vec2 Gravity(0.0f, 0.0f);
b2World World(Gravity);

int main()
{
	Game game(ResolutionX, ResolutionY, Vsync, Fullscreen);
	Entity entity;
	entity.SetWorld(&World);

	game.PushState(new MenuState(&game));

	game.GameLoop();

	return 0;
}