#include "TextureManager.h"

TextureManager::TextureManager()
{
    std::string path ("../Res/Textures/");

    registerResource(TextureID::Splash_SFML,   path + "Splash/SFML.png");
    registerResource(TextureID::Splash_MH,     path + "Splash/MatthewHopson.png");
    registerResource(TextureID::Arrow_Test,    path + "Arrows.png");
}
