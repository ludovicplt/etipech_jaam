#include "SoundManager.h"

SoundManager::SoundManager()
{
    std::string path ("../Res/Sounds/");

    registerResource(SoundID::splashMadeBy, path + "MadeBy.ogg");
}
