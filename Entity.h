#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "SpriteManager.h"
#include "WorldContainer.h"
#include <vector>

using namespace sf;
enum State
{
	IDLE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

class Entity
{
protected:
	const float SCALE = 30.0f;		//перевод метров Box2D в пиксели
	const float DEG = 57.29577f;	//радиан в градусах
	float Scale = 1; 
	float density = 1.0f;
	float friction = 1.0f;
	float Width = 0;
	float Height = 0;
	const char* Tag = "";
	int ID = 0;
	int Frames = 0;
	int Rows = 0;
	int AnimationSpeed = 0;
	State CurrentState = IDLE;

	SpriteManager& Sprite_Manager = SpriteManager::GetSpriteManager();
	WorldContainer& World_Container = WorldContainer::GetWorldContainer();

	Sprite sprite;					//ѕараметры спрайта
	Vector2f Gr_Pos;
	IntRect InitRect;

	b2Vec2 CurrentVelocity;
	b2Vec2 MaxVelocity;
	b2Vec2 Ph_Pos;					//ѕараметры физического тела
	b2BodyDef BodyDef;
	b2PolygonShape Ph_Shape;
	b2FixtureDef FixtureDef;
	b2Body* Body = nullptr;
	b2World* World = World_Container.GetWorld();
	
public:
	Entity() {}
	virtual ~Entity() {} 
	
	void SetPositionFromPh(b2Vec2 Position);		// оординаты центра
	void SetVelocity(float vel_x, float vel_y);
	b2Vec2 GetVelocity();
	b2Vec2 GetMaximumVelocity();
	b2Body* GetBody();
	Vector2f GetPosition();
	Vector2f GetCenter();
	const char* GetTag();
	void Rotate(bool flag);							//true если может вращатьс€
	void SetSprite(Sprite& s);
	void SetScale(float scale);
	float GetScale();
	int GetID();
	State GetState();
	void SetState(State state);
	IntRect GetRect();
	void SetRect(IntRect rect);
	int GetFrames();
	int GetRows();
	int GetAnimationSpeed();
	Sprite* GetSprite();

	virtual void Update() = 0;
	virtual void Draw(RenderWindow* window, float dt) = 0;
};

