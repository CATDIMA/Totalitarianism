#include "SpriteCreater.h"
#include "SFML/Graphics.hpp"

using namespace sf;

Sprite SpriteCreator::CreateSprite(Texture& texture, float& scale)
{
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	return sprite;
}
