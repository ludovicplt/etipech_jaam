#ifndef FONT_MANAGER_H_INCLUDED
#define FONT_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

enum class FontID
{
    rs
};

class FontManager : public ResourceManager<sf::Font, FontID>
{
    public:
        FontManager();

};


#endif // FONT_MANAGER_H_INCLUDED
