#include "TextureManager.h"

TextureManager::TextureManager()
{
    std::string path ("../Res/Textures/");

    registerResource(TextureID::splashSFML, path + "Splash/SFML.png");
    registerResource(TextureID::splashMH, path + "Splash/MatthewHopson.png");
    registerResource(TextureID::arrowTest, path + "Arrows.png");
}
