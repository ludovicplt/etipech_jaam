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

namespace State 
{
    LabReceptionState::LabReception::LabReception(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
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
        this->m_labReception.push_back({1.4, this->getTexture(TextureID::labReception)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 31, 0, 31, 31}, 0.1);
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
        m_animSprite.setTextureRect(m_anim.getFrame());
        player.update(dt);
    }

    void LabReceptionState::draw()
    {
        this->m_labReception.front().draw();
        Display::draw(m_animSprite);
        player.draw();
    }
}