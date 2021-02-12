#include "FontManager.h"

FontManager::FontManager()
{
    std::string path ("../Res/Fonts/");

    registerResource(FontID::RS, path + "rs.ttf");
}
