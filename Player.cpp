#include "Player.h"

Player::Player(float xpos, float ypos)
{
	Gr_Pos.x = xpos;
	Gr_Pos.y = ypos;

	Ph_Pos.x = xpos / SCALE;
	Ph_Pos.y = ypos / SCALE;

	sprite = Sprite_Creator.CreateSprite("Player", 2.0f);

	Ph_Shape.SetAsBox(Width * Scale / SCALE, Height * Scale / SCALE);
	FixtureDef.shape = &Ph_Shape;
	FixtureDef.friction = friction;
	FixtureDef.density = density;
	BodyDef.position.Set(Ph_Pos.x, Ph_Pos.y);

	BodyDef.type = b2_dynamicBody;
	BodyDef.allowSleep = true;
	BodyDef.awake = true;
	BodyDef.fixedRotation = true;

	Body = World->CreateBody(&BodyDef);
	Body->CreateFixture(&FixtureDef);
	Body->SetUserData(&tag);
}

Sprite Player::GetSprite()
{
	return sprite;
}

void Player::Draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Player::Update()
{
	
}

