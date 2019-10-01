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
		viewPosition.x = static_cast<float>(resX / 2);
	}
	if (Position.y < (resY / 2))
	{
		viewPosition.y = static_cast<float>(resY / 2);
	}
	if (Position.x > (sizeX - resX / 2))
	{
		viewPosition.x = static_cast<float>(sizeX - resX / 2);
	}
	if (Position.y > (sizeY - resY / 2))
	{
		viewPosition.y = static_cast<float>(sizeY - resY / 2);
	}
	view.setCenter(viewPosition);
}

void Camera::SetMapSize(int sizex, int sizey)
{
	sizeX = sizex;
	sizeY = sizey;
}
