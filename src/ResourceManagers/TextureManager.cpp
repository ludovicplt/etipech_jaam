#include "TextureManager.h"

TextureManager::TextureManager()
{
    const std::string path ("../Res/Textures/");

    registerResource(TextureID::splashSFML, path + "Splash/SFML.png");
    registerResource(TextureID::splashMH, path + "Splash/risitas.png");
    registerResource(TextureID::arrowTest, path + "Arrows.png");
    registerResource(TextureID::player, path + "player.png");
    registerResource(TextureID::Office, path + "Office.png");
    registerResource(TextureID::background, path + "menu_fond.png");
    registerResource(TextureID::buttons, path + "buttons.png");
}