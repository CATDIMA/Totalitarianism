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

	const float SCALE = 30.0f;		//������� ������ Box2D � �������
	const float DEG = 57.29577f;	//������ � ��������
	float Scale = 1; 

	Sprite sprite;					//��������� �������
	Vector2f Gr_Pos;

	b2Vec2 Ph_Pos;					//��������� ����������� ����
	b2BodyDef BodyDef;
	b2PolygonShape Shape;
	b2FixtureDef FixtureDef;

	std::multimap<int, Entity*> Entities;	//TODO ����������� � �������� ������

	friend EntityManager;
};

