#include "TextureManager.h"

TextureManager::TextureManager()
{
    const std::string path ("../Res/Textures/");

    registerResource(TextureID::splashSFML, path + "Splash/SFML.png");
    registerResource(TextureID::splashMH, path + "Splash/risitas.png");
    registerResource(TextureID::arrowTest, path + "Arrows.png");
    registerResource(TextureID::sky, path + "sky.png");
    registerResource(TextureID::buildings, path + "buildings.png");
    registerResource(TextureID::road, path + "road.png");
    registerResource(TextureID::player, path + "player.png");
}
