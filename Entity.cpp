#include "Entity.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void Entity::SetPosition(float pos_x, float pos_y)
{
	Gr_Pos.x = pos_x;
	Gr_Pos.y = pos_y;
	sprite.setOrigin(Gr_Pos);

	Ph_Pos.x = pos_x / SCALE;
	Ph_Pos.y = pos_y / SCALE;
	BodyDef.position.Set(Ph_Pos.x, Gr_Pos.y);
}

void Entity::SetVelocity(float vel_x, float vel_y)
{
	CurrentVelocity.x = vel_x;
	CurrentVelocity.y = vel_y;
}

b2Vec2 Entity::GetVelocity()
{
	return CurrentVelocity;
}

Vector2f Entity::GetPosition()
{
	return Gr_Pos;
}

void Entity::Rotate(bool flag)
{
	BodyDef.fixedRotation = flag;
}

void Entity::SetSprite(Sprite& s)
{
	sprite = s;
}

void Entity::SetScale(float scale)
{
	Scale = scale;
}

float Entity::GetScale()
{
	return Scale;
}
