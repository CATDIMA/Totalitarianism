#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "SpriteManager.h"
#include "WorldContainer.h"
#include <vector>

using namespace sf;

class Entity
{
public:
	Entity() {}
	virtual ~Entity() {}
protected:
	const float SCALE = 30.0f;		//перевод метров Box2D в пиксели
	const float DEG = 57.29577f;	//радиан в градусах
	float Scale = 1; 
	float density = 1.0f;
	float friction = 1.0f;

	SpriteManager& Sprite_Manager = SpriteManager::GetSpriteManager();
	WorldContainer& World_Container = WorldContainer::GetWorldContainer();

	Sprite sprite;					//ѕараметры спрайта
	Vector2f Gr_Pos;

	b2Vec2 CurrentVelocity;
	b2Vec2 MaxVelocity;
	b2Vec2 Ph_Pos;					//ѕараметры физического тела
	b2BodyDef BodyDef;
	b2PolygonShape Ph_Shape;
	b2FixtureDef FixtureDef;
	b2Body* Body = nullptr;
	b2World* World = World_Container.GetWorld();
	
public:
	void SetPosition(float pos_x, float pos_y);		// оординаты центра
	void SetVelocity(float vel_x, float vel_y);
	b2Vec2 GetVelocity();
	Vector2f GetPosition();
	void Rotate(bool flag);							//true если может вращатьс€
	void SetSprite(Sprite& s);
	void SetScale(float scale);
	float GetScale();
	virtual void Update() = 0;
	virtual void Draw(RenderWindow* window) = 0;
};

