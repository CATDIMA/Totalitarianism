#include "SpriteCreator.h"
#include "SFML/Graphics.hpp"
#include <string>

using namespace sf;

Sprite SpriteCreator::CreateSprite(const std::string& ResourceName, float scale, IntRect r)
{
	sprite.setTexture(*(texture_manager.GetTexture(ResourceName)));
	sprite.setTextureRect(r);
	sprite.setScale(scale, scale);
	return sprite;
}
