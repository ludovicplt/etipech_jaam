#include "PastTacosCity.h"
#include "PlayingState.h"
#include "../Application.h"
#include "../Display.h"



namespace State
{
    PastTacosCity::PastTacosCity(Application& application) :
            StateBase (application),
            player(application)
    {
        player.setSize({1, 1});
        player.setPos({0, 180});
        viewPort = std::make_unique<sf::View>(sf::FloatRect(0, 0, 1080 / 2.2 - 50, 720 / 2.2 - 50));
        Display::getWindow().setView(*viewPort);
        world = std::make_unique<WorldObject::WorldLoader>("../src/maps/TacosCity.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _Box(new Objects::CollidableBox);
                _Box->setBounds(world->getRect(i));
                player.addCollidable(std::move(_Box));
            }
        }
    }

    void PastTacosCity::input(const sf::Event& e)
    {
        player.input(e);
        Display::getWindow().setView(*viewPort);

        if (e.type == e.KeyPressed && e.key.code == sf::Keyboard::R)
        {
            m_p_application->pushState(std::make_unique<State::PastTacosCity>(*m_p_application));
        }
    }

    void PastTacosCity::input()
    {
    }

    void PastTacosCity::update(float dt)
    {
        player.update(dt);
        std::cout << "Pos: " << player.getPos().left << ", " << player.getPos().top << std::endl;
        if (player.getPos().left >= 720 / 3 - 22.128455 && player.getPos().left < 1800)
            viewPort->setCenter(player.getPos().left, viewPort->getCenter().y);
        Display::getWindow().setView(*viewPort);
    }

    void PastTacosCity::draw()
    {
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getSprite(i))
                Display::draw(*world->getSprite(i));
        }
        player.draw();
    }
}