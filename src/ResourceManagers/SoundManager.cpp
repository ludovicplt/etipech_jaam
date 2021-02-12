#include "SoundManager.h"

SoundManager::SoundManager()
{
    std::string path ("../Res/Sounds/");

    registerResource(SoundID::Splash_Made_By, path + "MadeBy.ogg");
}
