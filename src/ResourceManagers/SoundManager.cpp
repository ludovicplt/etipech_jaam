#include "SoundManager.h"

SoundManager::SoundManager()
{
    std::string path ("../Res/Sounds/");

    registerResource(SoundID::test, path + "test.ogg");
}
