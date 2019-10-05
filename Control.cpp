#include "Control.h"
#include <string>

using namespace std;

void Control::EnableKeyboard(Entity* ent)
{
	b2Body* body = ent->GetBody();
	b2Vec2 MaximumVelocity = ent->GetMaximumVelocity();
	b2Vec2 Velocity = body->GetLinearVelocity();

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
	if (Velocity.x > -MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(-MaximumVelocity.x * 5, Velocity.y), 1);
			ent->SetState(LEFT);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (Velocity.x < MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(MaximumVelocity.x * 5, Velocity.y), 1);
			ent->SetState(RIGHT);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Velocity.y < MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(Velocity.x, MaximumVelocity.y * 5), 1);
			ent->SetState(DOWN);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Velocity.y > -MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(Velocity.x, -MaximumVelocity.y * 5), 1);
			ent->SetState(UP);
		}
	}
	else
	{
		ent->SetState(IDLE);
	}
	ent->SetPositionFromPh(body->GetPosition());
}

void Control::EnableMouse()
{
}
