/*
** EPITECH PROJECT, 2021
** LabReceptionState.cpp
** File description:
** LabReceptionState
*/

#include "../Application.h"
#include "../Display.h"
#include "LabReceptionState.h"
#include "PlayingState.h"
#include "../WorldObject.h"
#include "../CollidableBox.h"
#include "LabEndingState.h"

namespace State 
{
    LabReceptionState::LabReception::LabReception(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({1080, Display::HEIGHT});
        this->m_sprite.setTextureRect({ 28, 6, 192, 113 });
        this->m_sprite.setPosition(-4, 0);
        this->m_sprite.setTexture(&back);
    }

    LabReceptionState::LabReception::LabReception(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
        //this->m_sound = std::make_unique<sf::Sound>(sound);
    }

    void LabReceptionState::LabReception::start()
    {
        if (this->m_sound)
            this->m_sound->play();
        this->m_clock.restart();
    }

    void LabReceptionState::LabReception::draw()
    {
        Display::draw(this->m_sprite);
    }

    bool LabReceptionState::LabReception::isOver()
    {
        return this->m_clock.getElapsedTime().asSeconds() >= this->m_time;
    }

    LabReceptionState::LabReceptionState(Application &application) 
    : StateBase (application), player(application)
    {
        player.setSize({2, 2});
        player.setPos({ 10, 500 });
        this->m_labReception.push_back({1.4, this->getTexture(TextureID::labReception)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        world = std::make_unique<WorldObject::WorldLoader>("../src/maps/LabReception.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _Box(new Objects::CollidableBox);
                _Box->setBounds(world->getRect(i));
                player.addCollidable(std::move(_Box));
            }
        }
        m_ViewPort = std::make_unique<sf::View>(sf::Rect<float>(0, 0, Display::WIDTH, Display::HEIGHT));
        Display::getWindow().setView(*m_ViewPort);
    }

    void LabReceptionState::input(const sf::Event& e)
    {
        player.input(e);
    }

    void LabReceptionState::input()
    {
    }

    void LabReceptionState::update(float dt)
    {
        player.update(dt);

        if (player.getPos().intersects({ 165,   -40,    275,   10 }) // first door
            || player.getPos().intersects({ 800,   -40,    275,   10 })) // second door
        {
            std::unique_ptr<State::LabEndingState> endingState = std::make_unique<State::LabEndingState>(*m_p_application);
            endingState->setStartPosition({ player.getPos().left, 500 });
            player.setPos({ player.getPos().left, player.getPos().top + 10 });
            m_p_application->pushState(std::move(endingState));
        }

        if (player.getPos().intersects({ -30,    400,    10,   300 }))
        {
            m_p_application->popState();
        }
    }

    void LabReceptionState::draw()
    {
        this->m_labReception.front().draw();
        player.draw();
    }
}