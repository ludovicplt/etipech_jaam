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
#include "../CollidableBox.h"
#include "LabReceptionState.h"
#include "PastOffice.h"
#include "../EntityParser.h"

namespace State 
{
    LabEndingState::LabEnding::LabEnding(float time, const sf::Texture& back)
    {
        this->m_time = time;
        this->m_sprite.setSize({1080, Display::HEIGHT});
        this->m_sprite.setTextureRect({ 28, 6, 192, 113 });
        this->m_sprite.setPosition(-4, 0);
        this->m_sprite.setTexture(&back);
    }

    LabEndingState::LabEnding::LabEnding(float time, const sf::Texture& back, const sf::SoundBuffer& sound)
    {
        this->m_time = time;
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
    : StateBase (application),
      player(application),
      warp("../src/maps/LabReceptionEntity.csv")

    {
        player.setSize({2, 2});
        player.setPos({400, 300});
        this->m_labEnding.push_back({1.4, this->getTexture(TextureID::labEnding)});
        //this->m_animSprite.setTexture(&this->getTexture(TextureID::player));

        world = std::make_unique<WorldObject::WorldLoader>("../src/maps/LabEnding.csv", application);
        for (int i = 0; i < world->getMapSize(); i++) {
            if (world->getIsCollidable(i) == true) {
                std::unique_ptr<Objects::CollidableBox> _Box(new Objects::CollidableBox);
                _Box->setBounds(world->getRect(i));
                player.addCollidable(std::move(_Box));
            }
        }
    }

    void LabEndingState::input(const sf::Event& e)
    {
        player.input(e);
        if (warp.getPos(0).intersects(player.getPos()) && e.type == e.KeyPressed && e.key.code == sf::Keyboard::Enter)
            m_p_application->pushState(std::make_unique<State::PastOffice>(*m_p_application));
    }

    void LabEndingState::input()
    {
    }

    void LabEndingState::update(float dt)
    {
        player.update(dt);

        if (player.getPos().intersects({ 165,   700,    275,   10 }) // first door
            || player.getPos().intersects({ 800,   700,    275,   10 })) // second door
        {
            Application *app = m_p_application;
            sf::Rect<float> pos = player.getPos();
            app->popState();
            app->setStatePlayerPos({pos.left, 20});
        }
    }

    void LabEndingState::draw()
    {
        this->m_labEnding.front().draw();
        player.draw();
    }
}