#ifndef SOUND_MANAGER_H_INCLUDED
#define SOUND_MANAGER_H_INCLUDED

#include <SFML/Audio.hpp>

#include "ResourceManager.h"

enum class SoundID
{
    splashMadeBy,
    test
};

class SoundManager : public ResourceManager<sf::SoundBuffer, SoundID>
{
    public:
        SoundManager();
};

#endif // SOUND_MANAGER_H_INCLUDED
