/*
** EPITECH PROJECT, 2021
** LabEndingState.hpp
** File description:
** LabEndingState
*/

#ifndef LabEndingState_H_
#define LabEndingState_H_

#include <stack>
#include <memory>
#include "StateBase.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Animation.h"
#include "../PlayerController.h"
#include "../WorldObject.h"
#include "../EntityParser.h"

namespace State 
{
    class LabEndingState : public StateBase 
    {
        class LabEnding
        {
            public:
                LabEnding(float time, const sf::Texture& back);
                LabEnding(float time, const sf::Texture& back, const sf::SoundBuffer& sound);

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
            LabEndingState (Application& application);

            void input(const sf::Event& e) override;
            void input() override;
            void update(float dt) override;
            void draw() override;

            void setStartPosition(sf::Vector2<float> pos) {
                player.setPos(pos);
            }
        private:
            std::unique_ptr<WorldObject::WorldLoader> world;
            sf::RectangleShape m_animSprite;
            Animation m_anim;
            PlayerController player;
            std::vector<LabEnding>  m_labEnding;
            sf::RectangleShape  m_fadeSprite;
            SplashState         m_currSplashState   = SplashState::Enter;
            int                 m_currAlphaValue    = 255;
            Entity::Pnj warp;

    };
}

#endif /* !LabEndingState_H_ */