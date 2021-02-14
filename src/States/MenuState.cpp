//
// Created by huntears on 2/13/21.
//

#include <iostream>

#include "MenuState.h"
#include "PlayingState.h"

#include "../Display.h"
#include "../Application.h"

namespace State {
    Menu::Menu(Application& application) :
            StateBase (application)
    {
        _playButton.setSize(sf::Vector2f(200.f, 100.f));
        _playButton.setFillColor(sf::Color::Blue);
        _playButton.setPosition(sf::Vector2f(5.f, 0.f));
        _playButton.setOutlineColor(sf::Color::White);
        _optionButton.setSize(sf::Vector2f(200.f, 100.f));
        _optionButton.setFillColor(sf::Color::Red);
        _optionButton.setPosition(sf::Vector2f(5.f, 105.f));
        _optionButton.setOutlineColor(sf::Color::White);
        _quitButton.setSize(sf::Vector2f(200.f, 100.f));
        _quitButton.setFillColor(sf::Color::Green);
        _quitButton.setPosition(sf::Vector2f(5.f, 210.f));
        _quitButton.setOutlineColor(sf::Color::White);
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
                m_p_application->pushState(std::make_unique<State::Playing>(*m_p_application));
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

    bool Menu::mouseIntersectsWithRectangle(const sf::RectangleShape &shape, const sf::Vector2f &cursorPos) const
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
        _selected == chosenOption::play ? _playButton.setOutlineThickness(5) : _playButton.setOutlineThickness(0);
        _selected == chosenOption::option ? _optionButton.setOutlineThickness(5) : _optionButton.setOutlineThickness(0);
        _selected == chosenOption::quit ? _quitButton.setOutlineThickness(5) : _quitButton.setOutlineThickness(0);
    }

    void Menu::draw()
    {
        Display::clear();
        Display::draw(_playButton);
        Display::draw(_optionButton);
        Display::draw(_quitButton);
    }
}