#pragma once
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

using namespace sf;
class StaticEntity : protected Entity
{
protected:
	StaticEntity();
	~StaticEntity() {}

	const float SCALE = 30.0f;		//������� ������ Box2D � �������
	const float DEG = 57.29577f;	//������ � ��������

public:

	void Init();
	void SetPosition(float pos_x, float pos_y);		//���������� ������
	Vector2f GetPosition();
	void SetSprite(Texture& texture);
	void SetScale(float scale);
	float GetScale();
};