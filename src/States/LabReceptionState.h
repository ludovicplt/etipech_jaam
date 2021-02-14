/*
** EPITECH PROJECT, 2021
** LabReceptionState.hpp
** File description:
** LabReceptionState
*/

#ifndef LabReceptionState_H_
#define LabReceptionState_H_

#include <stack>
#include <memory>
#include "StateBase.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Animation.h"
#include "../PlayerController.h"
#include "../WorldObject.h"

namespace State 
{
    class LabReceptionState : public StateBase 
    {
        class LabReception
        {
            public:
                LabReception(float time, const sf::Texture& back);
                LabReception(float time, const sf::Texture& back, const sf::SoundBuffer& sound);

                void start();
                void draw();
                bool isOver();

            private:
                float m_time;
                sf::RectangleShape m_sprite;
                sf::Clock m_clock;
                std::unique_ptr<sf::Sound> m_sound;
        };

        enum class SplashState
        {
            Enter,
            Active,
            Exiting
        };

        public:
            LabReceptionState (Application& application);

            void input(const sf::Event& e) override;
            void input() override;
            void update(float dt) override;
            void draw() override;

            void setPlayerPos(sf::Vector2<float> pos) override {
                player.setPos(pos);
            }
        private:
            std::unique_ptr<WorldObject::WorldLoader> world;
            sf::RectangleShape m_animSprite;
            Animation m_anim;
            PlayerController player;
            std::vector<LabReception>  m_labReception;
            sf::RectangleShape  m_fadeSprite;
            SplashState         m_currSplashState   = SplashState::Enter;
            int                 m_currAlphaValue    = 255;
            std::unique_ptr<sf::View> m_ViewPort;

    };
}

#endif /* !LabReceptionState_H_ */