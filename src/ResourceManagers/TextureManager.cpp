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
    registerResource(TextureID::Office, path + "Office.png");
    registerResource(TextureID::TacosCity, path + "TacosCity.png");
    registerResource(TextureID::background, path + "menu_fond.png");
    registerResource(TextureID::buttons, path + "buttons.png");
    registerResource(TextureID::labEntry, path + "lab_entry.png");
    registerResource(TextureID::labReception, path + "lab_reception.png");
    registerResource(TextureID::labEnding, path + "lab_ending.png");
}