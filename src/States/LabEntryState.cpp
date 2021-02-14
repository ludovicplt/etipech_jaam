/*
** EPITECH PROJECT, 2021
** LabEntryState.cpp
** File description:
** LabEntryState
*/

#include "../Application.h"
#include "../Display.h"
#include "../CollidableBox.h"
#include "../WorldObject.h"
#include "../ResourceManagers/ResourceManager.h"
#include "LabReceptionState.h"
#include "LabEntryState.h"
#include "PlayingState.h"
#include <iostream>

namespace State 
{
    LabEntryState::LabEntry::LabEntry(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
    }

    LabEntryState::LabEntry::LabEntry(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
        //this->m_sound = std::make_unique<sf::Sound>(sound);
    }

    void LabEntryState::LabEntry::start()
    {
        if (this->m_sound)
            this->m_sound->play();
        this->m_clock.restart();
    }

    void LabEntryState::LabEntry::draw()
    {
        Display::draw(this->m_sprite);
    }

    bool LabEntryState::LabEntry::isOver()
    {
        return this->m_clock.getElapsedTime().asSeconds() >= this->m_time;
    }

    LabEntryState::LabEntryState(Application &application) 
    : StateBase (application),
      player(application)
    {
        this->m_labEntry.push_back({1.4, this->getTexture(TextureID::labEntry)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        
        world = std::make_unique<WorldObject::WorldLoader>("../src/maps/LabEntry.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _Box(new Objects::CollidableBox);
                _Box->setBounds(world->getRect(i));
                player.addCollidable(std::move(_Box));
            }
        }

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 31, 0, 31, 31}, 0.1);
        this->m_viewPort = std::make_unique<sf::View>(sf::Rect<float>(200, 0, 1080, 720));
        Display::getWindow().setView(*this->m_viewPort);
        player.setSize(sf::Vector2<float>(1.75, 1.75));
    }

    void LabEntryState::input(const sf::Event& e)
    {
        player.input(e);
    }

    void LabEntryState::input()
    {
    }

    void LabEntryState::update(float dt)
    {
        if (player.getPos().intersects(world->getRect(5)))
            this->m_p_application->pushState(std::make_unique<State::LabReceptionState>(*m_p_application));
        m_animSprite.setTextureRect(m_anim.getFrame());
        player.update(dt);
    }

    void LabEntryState::draw()
    {
        this->m_labEntry.front().draw();
        Display::draw(m_animSprite);
        player.draw();
    }
}