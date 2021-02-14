#ifndef TEXTURE_MANAGER_H_INCLUDED
#define TEXTURE_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"


enum class TextureID
{
    splashSFML,
    splashMH,
    arrowTest,
    player,
    alexandroFlioSign,
    alexandroFlioVehicle,
    past2Background
};

class TextureManager : public ResourceManager<sf::Texture, TextureID>
{
    public:
        TextureManager();
};

#endif // TEXTURE_MANAGER_H_INCLUDED
