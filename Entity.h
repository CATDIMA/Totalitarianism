#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

using namespace sf;

class EntityManager;

class Entity
{
protected:
	Entity() {}
	virtual ~Entity() {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	const float SCALE = 30.0f;		//перевод метров Box2D в пиксели
	const float DEG = 57.29577f;	//радиан в градусах
	float Scale = 1; 

	Sprite sprite;					//Параметры спрайта
	Vector2f Gr_Pos;

	b2Vec2 Ph_Pos;					//Параметры физического тела
	b2BodyDef BodyDef;
	b2PolygonShape Shape;
	b2FixtureDef FixtureDef;

	std::multimap<int, Entity*> Entities;	//TODO переместить в менеджер энтити

	friend EntityManager;
};

