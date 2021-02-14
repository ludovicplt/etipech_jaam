/*
** EPITECH PROJECT, 2021
** LabEndingState.cpp
** File description:
** LabEndingState
*/

#include "../Application.h"
#include "../Display.h"
#include "LabEndingState.h"
#include "PlayingState.h"

namespace State 
{
    LabEndingState::LabEnding::LabEnding(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
    }

    LabEndingState::LabEnding::LabEnding(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
        //this->m_sound = std::make_unique<sf::Sound>(sound);
    }

    void LabEndingState::LabEnding::start()
    {
        if (this->m_sound)
            this->m_sound->play();
        this->m_clock.restart();
    }

    void LabEndingState::LabEnding::draw()
    {
        Display::draw(this->m_sprite);
    }

    bool LabEndingState::LabEnding::isOver()
    {
        return this->m_clock.getElapsedTime().asSeconds() >= this->m_time;
    }

    LabEndingState::LabEndingState(Application &application) 
    : StateBase (application), player(application)
    {
        this->m_labEnding.push_back({1.4, this->getTexture(TextureID::labEnding)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 31, 0, 31, 31}, 0.1);
    }

    void LabEndingState::input(const sf::Event& e)
    {
        player.input(e);
    }

    void LabEndingState::input()
    {
    }

    void LabEndingState::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
        player.update(dt);
    }

    void LabEndingState::draw()
    {
        this->m_labEnding.front().draw();
        Display::draw(m_animSprite);
        player.draw();
    }
}