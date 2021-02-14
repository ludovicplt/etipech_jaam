#include "PlayingState.h"

#include "../ResourceManagers/ResourceManager.h"
#include "../Application.h"
#include "../Display.h"

class issou : public ICollidable {
public:
    sf::RectangleShape box;
    void draw() const
    {
        Display::draw(box);
    }

    void update()
    {

    }

    inline virtual sf::Rect<float> getPos() const override
    {
        return box.getGlobalBounds();
    }
};

namespace State
{
    Playing::Playing(Application& application) :
        StateBase (application),
        player(application)
    {
        m_animSprite.setTexture(&getTexture(TextureID::arrowTest));
        m_animSprite.setSize({500, 500});

        std::unique_ptr<issou> box(new issou);
        box->box.setSize({100, 100});
        box->box.setPosition({400, 300});
        box->box.setFillColor(sf::Color::Yellow);
        player.addCollidable(std::move(box));

        for (int i = 0; i < 4 ; i++) {
            m_anim.addFrame({i * 16, 0, 16, 16}, 0.1);
        }
        m_text.setFont(getFont(FontID::rs));
        m_text.setString("Test.");
    }

    void Playing::input(const sf::Event& e)
    {
        player.input(e);
    }

    void Playing::input()
    {

    }

    void Playing::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
        player.update(dt);
    }

    void Playing::draw()
    {
        Display::draw(m_animSprite);
        Display::draw(m_text);
        player.draw();
    }

}
