#include "Player.h"

Player::Player(float xpos, float ypos, float scale)
{
	Scale = scale;
	Tag = "Player";

	Gr_Pos.x = xpos;
	Gr_Pos.y = ypos;

	Ph_Pos.x = xpos / SCALE;
	Ph_Pos.y = ypos / SCALE;

	IntRect TextureRect(0, 0, 11 ,32);
	Height = 32.0f;
	Width = 32.0f;
	
	sprite = *Sprite_Manager.GetSprite("Player", Scale, TextureRect);
	sprite.setPosition(Gr_Pos);

	CurrentVelocity.x = 0;
	CurrentVelocity.y = 0;
	
	MaxVelocity.x = 20.0f;
	MaxVelocity.y = 20.0f;

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
	Body->SetUserData(&Tag);
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
	sprite.setPosition(Body->GetPosition().x, Body->GetPosition().y);
}

