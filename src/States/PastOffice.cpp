#include "PastOffice.h"
#include "PlayingState.h"
#include "../Application.h"
#include "../Display.h"



namespace State
{
    PastOffice::PastOffice(Application& application) :
        StateBase (application),
        player(application),
        Entity("../src/maps/OfficeEntity.csv")
    {
        player.setSize({1.75, 1.75});
        player.setPos({0, 180});
        viewPort = std::make_unique<sf::View>(sf::FloatRect(0, 0, 1080 / 2.2 - 50, 720 / 2.2 - 50));
        Display::getWindow().setView(*viewPort);
        world = std::make_unique<WorldObject::WorldLoader>("../src/maps/Office.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _BoxBlock(new Objects::CollidableBox);
                _BoxBlock->setBounds(world->getRect(i));
                player.addCollidable(std::move(_BoxBlock));
            }
        }
    }

#define KEY_PRESSED(evt, kCode) (evt.type == evt.KeyPressed && evt.key.code == kCode)

    void PastOffice::input(const sf::Event& e)
    {
        player.input(e);
        Display::getWindow().setView(*viewPort);
        for (int i = 0; i < Entity.getSize(); i++) {
            if (Entity.IsIntersecting(player.getPos(), Entity.getPos(i)) && KEY_PRESSED(e, sf::Keyboard::Enter)) {
                sf::Text text;
                text.setString(Entity.getSpeech(i)); 
                Display::draw(text);
                std::cout << Entity.getSpeech(i) << std::endl;
            }
        }
    }

    void PastOffice::input()
    {

    }

    void PastOffice::update(float dt)
    {
        player.update(dt);
        
        if (player.getPos().left >= 720 / 2.2 - 43.127)
            viewPort->setCenter(player.getPos().left, (720 / 2.2 - 50) / 2);
        Display::getWindow().setView(*viewPort);
    }

    void PastOffice::draw()
    {
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getSprite(i))
                Display::draw(*world->getSprite(i));
        }
        player.draw();
    }
}