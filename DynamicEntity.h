#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

using namespace sf;
class DynamicEntity : protected Entity
{
protected:
	DynamicEntity();
	~DynamicEntity() {}

	const float SCALE = 30.0f;		//перевод метров Box2D в пиксели
	const float DEG = 57.29577f;	//радиан в градусах

	b2Vec2 CurrentVelocity;
	b2Vec2 MaxVelocity;				

public:

	void Init();
	void SetPosition(float pos_x, float pos_y);		//Координаты центра
	void SetVelocity(float vel_x, float vel_y);
	b2Vec2 GetVelocity();
	Vector2f GetPosition();
	void Rotate(bool flag);							//true если может вращаться
	void SetSprite(Texture& texture);
};