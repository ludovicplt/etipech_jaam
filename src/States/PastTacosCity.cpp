#include "PastTacosCity.h"
#include "../Application.h"
#include "../Display.h"
#include "../Util/Scaling.h"

namespace State
{
    PastTacosCity::PastTacosCity(Application &application) :
        StateBase(application)
    {
        m_background.setTexture(getTexture(TextureID::past2Background));
        m_background.setPosition(0, 0);
        Scaling::setSpriteWidthInPixels(m_background, 1200);
        Scaling::setSpriteWidthInPixels(m_alexandroFlioSign, 110);
        Scaling::setSpriteWidthInPixels(m_alexandroFlioVehicle, 415);
    }

    void PastTacosCity::input(const sf::Event& e)
    { }

    void PastTacosCity::input()
    { }

    void PastTacosCity::update(float dt)
    {

    }

    void PastTacosCity::draw()
    {
        Display::draw(m_background);
        Display::draw(m_alexandroFlioVehicle);
        Display::draw(m_alexandroFlioSign);
    }

}