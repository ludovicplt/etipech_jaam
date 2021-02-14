/*
** EPITECH PROJECT, 2021
** SpawnState.hpp
** File description:
** SpawnState
*/

#ifndef SpawnState_H_
#define SpawnState_H_

#include <stack>
#include <memory>
#include "StateBase.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Animation.h"
#include "../PlayerController.h"
#include "../WorldObject.h"
#include "../../src/CollidableBox.h"

namespace State 
{
    class SpawnState : public StateBase 
    {
        class Spawn
        {
            public:
                Spawn(float time, const sf::Texture& back);
                Spawn(float time, const sf::Texture& back, const sf::SoundBuffer& sound);

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
            SpawnState (Application& application);

            void input(const sf::Event& e) override;
            void input() override;
            void update(float dt) override;
            void draw() override;
        private:
            std::unique_ptr<WorldObject::WorldLoader> world;
            sf::RectangleShape m_animSprite;
            Animation m_anim;
            PlayerController player;
            std::vector<Spawn>  m_spawn;
            sf::RectangleShape  m_fadeSprite;
            SplashState         m_currSplashState   = SplashState::Enter;
            int                 m_currAlphaValue    = 255;
            std::unique_ptr<sf::View> m_viewPort;
            Objects::CollidableBox _BoxBlock;

    };
}

#endif /* !SpawnState_H_ */