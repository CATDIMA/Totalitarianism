#include "Control.h"
#include "Control.h"

void Control::EnableKeyboard(Entity* ent)
{
	b2Body* body = ent->GetBody();
	b2Vec2 MaximumVelocity = ent->GetMaximumVelocity();
	b2Vec2 Velocity = ent->GetVelocity();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
	if (ent->GetVelocity().x > -MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(-MaximumVelocity.x, 0.0f), 1);
			
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
	 if (Velocity.x < MaximumVelocity.x)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(MaximumVelocity.x, 0.0f), 1);
			
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (Velocity.y < MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(10.0f, MaximumVelocity.y), 1);
			
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (Velocity.y > -MaximumVelocity.y)
		{
			body->ApplyLinearImpulseToCenter(b2Vec2(10.0f, -MaximumVelocity.y), 1);
			
		}
	}
	else
	{
		body->SetLinearVelocity(b2Vec2(0.0f, 0.0f));
	}
}

void Control::EnableMouse()
{
}
