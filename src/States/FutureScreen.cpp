/*
** EPITECH PROJECT, 2021
** FutureScreen.cpp
** File description:
** FutureScreen
*/

#include "../Application.h"
#include "../Display.h"
#include "FutureScreen.h"
#include "PlayingState.h"

namespace State 
{
    FutureScreen::Future::Future(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
    }

    FutureScreen::Future::Future(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
        this->m_sprite.setSize({Display::WIDTH, Display::HEIGHT});
        this->m_sprite.setTexture(&back);
        this->m_sound = std::make_unique<sf::Sound>(sound);
    }

    void FutureScreen::Future::start()
    {
        if (this->m_sound)
            this->m_sound->play();
        this->m_clock.restart();
    }

    void FutureScreen::Future::draw()
    {
        Display::draw(this->m_sprite);
    }

    bool FutureScreen::Future::isOver()
    {
        return this->m_clock.getElapsedTime().asSeconds() >= this->m_time;
    }

    FutureScreen::FutureScreen(Application &application) 
    : StateBase (application)
    {
        this->m_animSprite.setSize({100, 100});
        this->m_future.push_back({1.4, this->getTexture(TextureID::test), this->getSound(SoundID::test)});
        this->m_animSprite.setTexture(&this->getTexture(TextureID::character));

        for (int i = 0; i < 4; i++)
            this->m_anim.addFrame({i * 256, 0, 256, 256}, 0.1);
    }

    void FutureScreen::input(const sf::Event& e)
    {
    }

    void FutureScreen::input()
    {
    }

    void FutureScreen::update(float dt)
    {
        m_animSprite.setTextureRect(m_anim.getFrame());
    }

    void FutureScreen::draw()
    {
         if (!m_future.empty())
            for (int i = 0; i < this->m_future.size(); i++)
                this->m_future[i].draw();
        Display::draw(m_animSprite);
    }
}