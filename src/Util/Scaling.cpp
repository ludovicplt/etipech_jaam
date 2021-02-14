//
// Created by alexis on 2/13/21.
//

#include "Scaling.h"

void Scaling::setSpriteSizeInPixels(sf::Sprite& sprite, sf::Vector2<int> sizeInPixels)
{
    sf::Rect<int> rect = sprite.getTextureRect();
    sf::Vector2<float> scale = sprite.getScale();

    sprite.setScale(scale.x / (float)rect.width * sizeInPixels.x, scale.y / (float)rect.height * sizeInPixels.y);
}

void Scaling::setSpriteWidthInPixels(sf::Sprite &sprite, int width)
{
    sf::Rect<int> rect = sprite.getTextureRect();
    sf::Vector2<float> scale = sprite.getScale();

    sprite.setScale(scale.x / (float)rect.width * width, scale.y / (float)rect.width * width);
}