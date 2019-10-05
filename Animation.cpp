#include "Animation.h"

void Animation::Animate(Entity* entity, float dt)
{
	frames_ = entity->GetFrames();
	rows_ = entity->GetRows();
	rect_ = entity->GetRect();
	state_ = entity->GetState();
	frameSpeed_ = entity->GetAnimationSpeed();

	currentFrame_ = currentFrame_ + dt * frameSpeed_;
	if (currentFrame_ > frames_) { currentFrame_ = 0; }
	rect_.left = rect_.width * static_cast<int>(currentFrame_);
	switch (state_)
	{
	case IDLE:
	{
		rows_ = 0;
		entity->SetRect(IntRect(rect_.left, rows_ * rect_.height, rect_.width, rect_.height));
		break;
	}
	case LEFT:
	{
		rows_ = 1;
		entity->SetRect(IntRect(rect_.left + rect_.width, rows_ * rect_.height, -rect_.width, rect_.height));
		break;
	}
	case RIGHT:
	{
		rows_ = 1;
		entity->SetRect(IntRect(rect_.left, rows_ * rect_.height, rect_.width, rect_.height));
		break;
	}
	case UP:
	{
		rows_ = 0;
		entity->SetRect(IntRect(rect_.left, rows_ * rect_.height, rect_.width, rect_.height));
		break;
	}
	case DOWN:
	{
		rows_ = 0;
		entity->SetRect(IntRect(rect_.left, rows_ * rect_.height, rect_.width, rect_.height));
		break;
	}
	default:
		break;
	}
}
