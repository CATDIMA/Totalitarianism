#include "Entity.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void Entity::SetPositionFromPh(b2Vec2 Position)
{
	Gr_Pos.x = Position.x * SCALE;
	Gr_Pos.y = Position.y * SCALE;

	Ph_Pos = Position;
	sprite.setPosition(Gr_Pos.x, Gr_Pos.y);
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

b2Vec2 Entity::GetMaximumVelocity()
{
	return MaxVelocity;
}

b2Body* Entity::GetBody()
{
	return Body;
}

Vector2f Entity::GetPosition()
{
	return Gr_Pos;
}

Vector2f Entity::GetCenter()
{
	Gr_Pos.x - Width / 2;
	Gr_Pos.y - Height / 2;
	return Gr_Pos;
}

const char* Entity::GetTag()
{
	return Tag;
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

int Entity::GetID()
{
	return ID;
}

State Entity::GetState()
{
	return CurrentState;
}

void Entity::SetState(State state)
{
	CurrentState = state;
}

IntRect Entity::GetRect()
{
	return InitRect;
}

void Entity::SetRect(IntRect rect)
{
	InitRect = rect;
}

int Entity::GetFrames()
{
	return Frames;
}

int Entity::GetRows()
{
	return Rows;
}

int Entity::GetAnimationSpeed()
{
	return AnimationSpeed;
}

Sprite* Entity::GetSprite()
{
	return &sprite;
}
