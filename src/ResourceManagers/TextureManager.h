#ifndef TEXTURE_MANAGER_H_INCLUDED
#define TEXTURE_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"


enum class TextureID
{
    Splash_SFML,
    Splash_MH,

    Arrow_Test,
};

class TextureManager : public ResourceManager<sf::Texture, TextureID>
{
    public:
        TextureManager();
};

#endif // TEXTURE_MANAGER_H_INCLUDED
