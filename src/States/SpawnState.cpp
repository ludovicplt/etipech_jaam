/*
** EPITECH PROJECT, 2021
** SpawnState.cpp
** File description:
** SpawnState
*/

#include "../Application.h"
#include "../Display.h"
#include "SpawnState.h"
#include "LabEntryState.h"
#include "PlayingState.h"

namespace State 
{
    SpawnState::Spawn::Spawn(float time, const sf::Texture& back)
    {
        this->m_time = time;
        if (back.getSize().x == 321 && back.getSize().y == 101) {
            this->m_sprite.setPosition({0, 300});
            this->m_sprite.setSize({Display::WIDTH, 500});
            this->m_sprite.setTexture(&back);
        } else if (back.getSize().x == 632 && back.getSize().y == 34) {
            this->m_sprite.setPosition({0, 620});
            this->m_sprite.setSize({Display::WIDTH, 100});
            this->m_sprite.setTexture(&back);
            this->m_sprite.setTextureRect({0, 0, 300, 40});
        } else {
            this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
            this->m_sprite.setTexture(&back);
        }
    }

    SpawnState::Spawn::Spawn(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
        if (back.getSize().x == 321 && back.getSize().y == 101) {
            this->m_sprite.setPosition({0, 300});
            this->m_sprite.setSize({Display::WIDTH, 500});
            this->m_sprite.setTexture(&back);
        } else if (back.getSize().x == 632 && back.getSize().y == 34) {
            this->m_sprite.setPosition({0, 620});
            this->m_sprite.setSize({Display::WIDTH, 100});
            this->m_sprite.setTexture(&back);
            this->m_sprite.setTextureRect({0, 0, 300, 40});
        } else {
            this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
            this->m_sprite.setTexture(&back);
        }
        //this->m_sound = std::make_unique<sf::Sound>(sound);
    }

    void SpawnState::Spawn::start()
    {
        if (this->m_sound)
            this->m_sound->play();
        this->m_clock.restart();
    }

    void SpawnState::Spawn::draw()
    {
        Display::draw(this->m_sprite);
    }

    bool SpawnState::Spawn::isOver()
    {
        return this->m_clock.getElapsedTime().asSeconds() >= this->m_time;
    }

    SpawnState::SpawnState(Application &application) 
    : StateBase (application), player(application)
    {
        this->m_spawn.push_back({1.4, this->getTexture(TextureID::sky)});
        this->m_spawn.push_back({1.4, this->getTexture(TextureID::buildings)});
        this->m_spawn.push_back({1.4, this->getTexture(TextureID::road)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 31, 0, 31, 31}, 0.1);
    }

    void SpawnState::input(const sf::Event& e)
    {
        player.input(e);
    }

    void SpawnState::input()
    {
    }

    void SpawnState::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
        player.update(dt);
    }

    void SpawnState::draw()
    {
         if (!m_spawn.empty()) {
            for (int i = 0; i < this->m_spawn.size(); i++)
                this->m_spawn[i].draw();
            Display::draw(m_animSprite);
            player.draw();
        } //} else
        //     this->m_p_application->pushState(std::make_unique<State::LabEntryState>(*m_p_application));
    }
}