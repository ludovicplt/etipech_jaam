#include "PastOffice.h"
#include "PlayingState.h"
#include "../Application.h"
#include "../Display.h"

namespace State
{
    PastOffice::PastOffice(Application& application) :
        StateBase (application),
        player(application)
    {
        world = std::make_unique<WorldObject::WorldLoader>("../src/map.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _Box(new Objects::CollidableBox);
                _Box->setBounds(world->getRect(i));
                player.addCollidable(std::move(_Box));
            }
        }
    }

    void PastOffice::input(const sf::Event& e)
    {
        player.input(e);
    }

    void PastOffice::input()
    {

    }

    void PastOffice::update(float dt)
    {
        player.update(dt);
    }

    void PastOffice::draw()
    {
        player.draw();
        for (int i = 0; i < world->getMapSize(); i++) {
            Display::draw(*world->getSprite(i));
        }
    }

}