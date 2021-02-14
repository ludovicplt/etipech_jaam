#ifndef TEXTURE_MANAGER_H_INCLUDED
#define TEXTURE_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"


enum class TextureID
{
    splashSFML,
    splashMH,
    arrowTest,
    TacosCity = 3,
    Office = 4,
    player = 10,
    background,
    buttons,
    sky,
    buildings,
    road,
    labEntry,
    labReception,
    labEnding
};

class TextureManager : public ResourceManager<sf::Texture, TextureID>
{
    public:
        TextureManager();
};

#endif // TEXTURE_MANAGER_H_INCLUDED