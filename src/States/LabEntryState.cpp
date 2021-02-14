/*
** EPITECH PROJECT, 2021
** LabEntryState.cpp
** File description:
** LabEntryState
*/

#include "../Application.h"
#include "../Display.h"
#include "LabEntryState.h"
#include "PlayingState.h"

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
    : StateBase (application), player(application)
    {
        this->m_labEntry.push_back({1.4, this->getTexture(TextureID::labEntry)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 31, 0, 31, 31}, 0.1);
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