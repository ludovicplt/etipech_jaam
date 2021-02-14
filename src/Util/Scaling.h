//
// Created by alexis on 2/13/21.
//
#include <SFML/Graphics.hpp>

#ifndef SCALING_H
#define SCALING_H


namespace Scaling
{
    void setSpriteSizeInPixels(sf::Sprite& sprite, sf::Vector2<int> sizeInPixels);
    void setSpriteWidthInPixels(sf::Sprite& sprite, int width);
}


#endif //SCALING_H
