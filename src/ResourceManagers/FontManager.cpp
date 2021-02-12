#include "FontManager.h"

FontManager::FontManager()
{
    std::string path ("../Res/Fonts/");

    registerResource(FontID::rs, path + "rs.ttf");
}
