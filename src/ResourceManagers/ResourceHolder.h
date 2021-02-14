#ifndef RESOURCE_HOLDER_H_INCLUDED
#define RESOURCE_HOLDER_H_INCLUDED

#include "TextureManager.h"
#include "SoundManager.h"
#include "FontManager.h"

struct ResourceHolder
{
    TextureManager textures;
    FontManager    fonts;
    SoundManager   sounds;
};

#endif // RESOURCEHOLDER_H_INCLUDED
