#include "TextureManager.h"

TextureManager::TextureManager()
{
    std::string path ("../Res/Textures/");

    registerResource(TextureID::splashSFML, path + "Splash/SFML.png");
    registerResource(TextureID::splashMH, path + "Splash/risitas.png");
    registerResource(TextureID::arrowTest, path + "Arrows.png");
    registerResource(TextureID::alexandroFlioSign, path + "AlexandroFlioSign.png");
    registerResource(TextureID::alexandroFlioVehicle, path + "AlexandroFlioVehicle.png");
    registerResource(TextureID::past2Background, path + "PastCityBackground.png");
}
