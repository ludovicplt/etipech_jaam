//
// Created by huntears on 2/13/21.
//

#include <iostream>

#include "MenuState.h"
#include "PlayingState.h"
#include "PastTacosCity.h"

#include "../Display.h"
#include "../Application.h"
#include "SpawnState.h"

namespace State {
    Menu::Menu(Application& application) :
            StateBase (application)
    {
        _background.setTexture(getTexture(TextureID::background));

        _playButton.setTexture(getTexture(TextureID::buttons));
        _optionButton.setTexture(getTexture(TextureID::buttons));
        _quitButton.setTexture(getTexture(TextureID::buttons));

        _playButton.setTextureRect({0, 0, 354, 123});
        _optionButton.setTextureRect({0, 123 + 49, 354, 123});
        _quitButton.setTextureRect({0, 123 + 49 + 123 + 49, 354, 123});

        _playButton.setPosition(sf::Vector2f(800, 100.f));
        _optionButton.setPosition(sf::Vector2f(800, 300.f));
        _quitButton.setPosition(sf::Vector2f(800, 500.f));

        _music.openFromFile("../Res/Sounds/sweden.ogg");
        _music.setLoop(true);
        _music.setVolume(50);
        _music.play();
    }

    void Menu::switchOptionUp()
    {
        switch (_selected) {
            case chosenOption::play:
                _selected = chosenOption::quit;
                break;
            case chosenOption::option:
                _selected = chosenOption::play;
                break;
            case chosenOption::quit:
                _selected = chosenOption::option;
                break;
            default:
                std::cerr << "This should have never happened..." << std::endl;
                break;
        }
    }

    void Menu::switchOptionDown()
    {
        switch (_selected) {
            case chosenOption::play:
                _selected = chosenOption::option;
                break;
            case chosenOption::option:
                _selected = chosenOption::quit;
                break;
            case chosenOption::quit:
                _selected = chosenOption::play;
                break;
            default:
                std::cerr << "This should have never happened..." << std::endl;
                break;
        }
    }

    void Menu::executeButton(chosenOption option)
    {
        switch (option) {
            case chosenOption::play:
                _music.stop();
                m_p_application->pushState(std::make_unique<State::SpawnState>(*m_p_application));
                break;
            case chosenOption::option:
                // TODO
                std::cerr << "Not implemented yet !" << std::endl;
                break;
            case chosenOption::quit:
                Display::getWindow().close();
                break;
            default:
                std::cerr << "This should have never happened..." << std::endl;
                break;
        }
    }

    void Menu::executeButton()
    {
        executeButton(_selected);
    }

    void Menu::handleLeftClick()
    {
        const sf::Vector2<int> cursorPos = sf::Mouse::getPosition(Display::getWindow());
        const sf::Vector2<float> cursorPosFloat(cursorPos.x, cursorPos.y);

        if (mouseIntersectsWithRectangle(_playButton, cursorPosFloat)) {
            executeButton(chosenOption::play);
        }
        else if (mouseIntersectsWithRectangle(_optionButton, cursorPosFloat)) {
            executeButton(chosenOption::option);
        }
        else if (mouseIntersectsWithRectangle(_quitButton, cursorPosFloat)) {
            executeButton(chosenOption::quit);
        }
    }

    void Menu::handleMouseMoved()
    {
        const sf::Vector2<int> cursorPos = sf::Mouse::getPosition(Display::getWindow());
        const sf::Vector2<float> cursorPosFloat(cursorPos.x, cursorPos.y);

        if (mouseIntersectsWithRectangle(_playButton, cursorPosFloat)) {
            _selected = chosenOption::play;
        }
        else if (mouseIntersectsWithRectangle(_optionButton, cursorPosFloat)) {
            _selected = chosenOption::option;
        }
        else if (mouseIntersectsWithRectangle(_quitButton, cursorPosFloat)) {
            _selected = chosenOption::quit;
        }
    }

    bool Menu::mouseIntersectsWithRectangle(const sf::Sprite &shape, const sf::Vector2f &cursorPos) const
    {
        return shape.getGlobalBounds().contains(cursorPos);
    }

    void Menu::input(const sf::Event &e)
    {
        if (e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
                case sf::Keyboard::Escape:
                    Display::getWindow().close();
                    break;
                case sf::Keyboard::Enter:
                    executeButton();
                    break;
                case sf::Keyboard::Up:
                    switchOptionUp();
                    break;
                case sf::Keyboard::Down:
                    switchOptionDown();
                    break;
                default:
                    break;
            }
        }
        else if (e.type == sf::Event::MouseButtonPressed) {
            if (e.mouseButton.button == sf::Mouse::Left) {
                handleLeftClick();
            }
        }
        else if (e.type == sf::Event::MouseMoved) {
            handleMouseMoved();
        }
    }

    void Menu::input()
    {

    }

    void Menu::update(float dt)
    {
        _selected == chosenOption::play ? _playButton.setTextureRect({354 + 48, 0, 354, 123}) : _playButton.setTextureRect({0, 0, 354, 123});
        _selected == chosenOption::option ? _optionButton.setTextureRect({354 + 48, 123 + 49, 354, 123}) : _optionButton.setTextureRect({0, 123 + 49, 354, 123});
        _selected == chosenOption::quit ? _quitButton.setTextureRect({354 + 48, 123 + 49 + 123 + 49, 354, 123}) : _quitButton.setTextureRect({0, 123 + 49 + 123 + 49, 354, 123});
    }

    void Menu::draw()
    {
        Display::clear();
        Display::draw(_background);
        Display::draw(_playButton);
        Display::draw(_optionButton);
        Display::draw(_quitButton);
    }
}