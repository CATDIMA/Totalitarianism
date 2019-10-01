#include "Camera.h"

View* Camera::GetView()
{
	return &view;
}

void Camera::SetView(Vector2f Position)
{
	if (Position.x > (resX / 2))
	{
		viewPosition.x = Position.x;
	}
	if (Position.y > (resY / 2))
	{
		viewPosition.y = Position.y;
	}
	if (Position.x < (resX / 2))
	{
		viewPosition.x = Position.x + (resX / 2 - Position.x);
	}
	if (Position.y < (resY / 2))
	{
		viewPosition.y = Position.y + (resY / 2 - Position.y);
	}

	view.setCenter(viewPosition);
}
