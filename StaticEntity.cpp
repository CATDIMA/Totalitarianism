#include "StaticEntity.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

using namespace sf;

StaticEntity::StaticEntity()
{
	Init();
}

void StaticEntity::Init()
{
	BodyDef.allowSleep = true;
	BodyDef.awake = true;
	BodyDef.fixedRotation = true;
}

void StaticEntity::SetPosition(float pos_x, float pos_y)
{
	Gr_Pos.x = pos_x;
	Gr_Pos.y = pos_y;
	sprite.setOrigin(Gr_Pos);

	Ph_Pos.x = pos_x / SCALE;
	Ph_Pos.y = pos_y / SCALE;
	BodyDef.position.Set(Ph_Pos.x, Gr_Pos.y);
}

Vector2f StaticEntity::GetPosition()
{
	return Gr_Pos;
}

void StaticEntity::SetSprite(Texture& texture)
{
	sprite.setTexture(texture);
}

void StaticEntity::SetScale(float scale)
{
	Scale = scale;
}

float StaticEntity::GetScale()
{
	return Scale;
}
