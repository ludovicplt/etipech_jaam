#include "Display.h"

#include "States/StateBase.h"

namespace Display
{
    namespace
    {
        sf::RenderWindow window;

        void checkForClose(const sf::Event& e) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    void init(const std::string& name)
    {
        window.create({WIDTH, HEIGHT},
                       name,
                       sf::Style::Close);
        window.setFramerateLimit(240);
    }

    bool isOpen()
    {
        return window.isOpen();
    }

    void update()
    {
        window.display();
    }

    void clear (const sf::Color& colour)
    {
        window.clear(colour);
    }

    void draw(const sf::Drawable& drawable)
    {
        window.draw(drawable);
    }

    void pollEvents(State::StateBase& gameState)
    {
        sf::Event e;
        while (window.pollEvent(e)) {
            gameState.input(e);
            checkForClose(e);
        }
    }

    sf::RenderWindow &getWindow()
    {
        return window;
    }

}
