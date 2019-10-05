#include "Player.h"

Player::Player(float xpos, float ypos, float scale)
{
	Scale = scale;
	Tag = "Player";
	ID = 1;
	
	Gr_Pos.x = xpos;
	Gr_Pos.y = ypos;

	Ph_Pos.x = xpos / SCALE;
	Ph_Pos.y = ypos / SCALE;

	Height = 32.0f;
	Width = 11.0f;

	InitRect.left = 0;
	InitRect.top = 0;
	InitRect.width = Width;
	InitRect.height = Height;

	Frames = 3;
	AnimationSpeed = 12;

	sprite = *Sprite_Manager.GetSprite("Player", Scale, InitRect);
	sprite.setPosition(Gr_Pos);

	CurrentVelocity.x = 0;
	CurrentVelocity.y = 0;
	
	MaxVelocity.x = 20.0f;
	MaxVelocity.y = 20.0f;

	Ph_Shape.SetAsBox(Width * Scale / SCALE, Height * Scale / SCALE);
	FixtureDef.shape = &Ph_Shape;
	FixtureDef.friction = friction;
	FixtureDef.density = 0.5f;
	BodyDef.position.Set(Ph_Pos.x, Ph_Pos.y);

	BodyDef.type = b2_dynamicBody;
	BodyDef.allowSleep = true;
	BodyDef.awake = true;
	BodyDef.fixedRotation = true;

	Body = World->CreateBody(&BodyDef);
	Body->CreateFixture(&FixtureDef);
	Body->SetLinearDamping(100);
	Body->SetUserData((void*)(1));
}

Sprite Player::GetSprite()
{
	return sprite;
}

void Player::Draw(RenderWindow* window, float dt)
{
	Animator.Animate(this, dt);
	sprite.setTextureRect(InitRect);
	window->draw(sprite);
}

void Player::Update()
{
	sprite.setPosition(Body->GetPosition().x, Body->GetPosition().y);
}

