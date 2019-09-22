#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "SpriteCreator.h"
#include <vector>

using namespace sf;

class Entity
{
public:
	Entity() {}
	~Entity() {}
protected:
	const float SCALE = 30.0f;		//������� ������ Box2D � �������
	const float DEG = 57.29577f;	//������ � ��������
	float Scale = 1; 
	float density = 1.0f;
	float friction = 1.0f;

	Sprite sprite;					//��������� �������
	Vector2f Gr_Pos;

	b2Vec2 CurrentVelocity;
	b2Vec2 MaxVelocity;
	b2Vec2 Ph_Pos;					//��������� ����������� ����
	b2BodyDef BodyDef;
	b2PolygonShape Ph_Shape;
	b2FixtureDef FixtureDef;
	b2Body* Body = nullptr;
	b2World* World = nullptr;

	SpriteCreator& Sprite_Creator = SpriteCreator::GetSpriteCreator();
public:
	static std::vector<Entity*> Entities;
	void SetWorld(b2World* w)
	{
		World = w;
	}

	void SetPosition(float pos_x, float pos_y);		//���������� ������
	void SetVelocity(float vel_x, float vel_y);
	b2Vec2 GetVelocity();
	Vector2f GetPosition();
	void Rotate(bool flag);							//true ���� ����� ���������
	void SetSprite(Sprite& s);
	void SetScale(float scale);
	float GetScale();
	virtual void Update() {};
	virtual void Draw(RenderWindow* window) {};
};

