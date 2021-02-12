#include "PlayingState.h"

#include "../ResourceManagers/ResourceManager.h"
#include "../Application.h"
#include "../Display.h"

namespace State
{
    Playing::Playing(Application& application):
        StateBase (application)
    {
        m_animSprite.setTexture(&getTexture(TextureID::arrowTest));
        m_animSprite.setSize({500, 500});

        for (int i = 0; i < 4 ; i++) {
            m_anim.addFrame({i * 16, 0, 16, 16}, 0.1);
        }

        m_text.setFont(getFont(FontID::rs));
        m_text.setString("Test.");
    }

    void Playing::input(const sf::Event& e)
    {

    }

    void Playing::input()
    {

    }

    void Playing::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
    }

    void Playing::draw()
    {
        Display::draw(m_animSprite);
        Display::draw(m_text);
    }

}
