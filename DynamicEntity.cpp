#include "DynamicEntity.h"
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"

using namespace sf;

DynamicEntity::DynamicEntity()
{
	Init();
}

void DynamicEntity::Init()
{
	BodyDef.type = b2_dynamicBody;
	BodyDef.allowSleep = true;
	BodyDef.awake = true;
	BodyDef.fixedRotation = true;
}

void DynamicEntity::SetPosition(float pos_x, float pos_y)
{
	Gr_Pos.x = pos_x;
	Gr_Pos.y = pos_y;
	sprite.setOrigin(Gr_Pos);

	Ph_Pos.x = pos_x / SCALE;
	Ph_Pos.y = pos_y / SCALE;
	BodyDef.position.Set(Ph_Pos.x, Gr_Pos.y);
}

void DynamicEntity::SetVelocity(float vel_x, float vel_y)
{
	CurrentVelocity.x = vel_x;
	CurrentVelocity.y = vel_y;
}

b2Vec2 DynamicEntity::GetVelocity()
{
	return CurrentVelocity;
}

Vector2f DynamicEntity::GetPosition()
{
	return Gr_Pos;
}

void DynamicEntity::Rotate(bool flag)
{
	BodyDef.fixedRotation = flag;
}

void DynamicEntity::SetSprite(Texture& texture)
{
	sprite.setTexture(texture);
}

void DynamicEntity::SetScale(float scale)
{
	Scale = scale;
}

float DynamicEntity::GetScale()
{
	return Scale;
}
