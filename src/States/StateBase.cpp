#include "StateBase.h"

#include "../Application.h"

namespace State
{
    StateBase::StateBase(Application& app) :
        m_p_application (&app)
    {

    }

    const sf::Texture& StateBase::getTexture(TextureID id) const
    {
        return m_p_application->getResources().textures.get(id);
    }

    const sf::Font& StateBase::getFont(FontID id) const
    {
        return m_p_application->getResources().fonts.get(id);
    }

    const sf::SoundBuffer& StateBase::getSound(SoundID id) const
    {
        return m_p_application->getResources().sounds.get(id);
    }

}
