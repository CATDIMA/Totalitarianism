#include "Camera.h"

void Camera::CalculatePosition(float x, float y, int sizex, int sizey)
{
	if (x > (sizex / 2))
	{
		Position.x = x;
	}
	if (y > (sizey / 2))
	{
		Position.y = y;
	}
	if (x < (sizex / 2))
	{
		Position.x = x + (sizex / 2 - x);
	}
	if (y < (sizey / 2))
	{
		Position.y = y + (sizey / 2 - y);
	}
}

Vector2f Camera::GetPosition()
{
	return Position;
}
