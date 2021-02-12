#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    std::cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << std::endl;

    sf::Window App(sf::VideoMode(800, 600), "Etipech Jaajm");

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}