#include "Control.h"
#include <string>

using namespace std;

void Control::EnableKeyboard(Entity* ent)
{
	const char* t = ent->GetTag();
	b2Body* body = entityManager.SearchBodyByID(1);
	b2Vec2 MaximumVelocity = ent->GetMaximumVelocity();
	b2Vec2 Velocity = body->GetLinearVelocity();

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
	if (Velocity.x > -MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(-MaximumVelocity.x * 5, Velocity.y), 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Velocity.x < MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(MaximumVelocity.x * 5, Velocity.y), 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Velocity.y < MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(Velocity.x, MaximumVelocity.y * 5), 1);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Velocity.y > -MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(Velocity.x, -MaximumVelocity.y * 5), 1);
		}
	}
	else
	{
		body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
	}
	ent->SetPositionFromPh(body->GetPosition());
}

void Control::EnableMouse()
{
}
