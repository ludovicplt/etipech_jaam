/*
** EPITECH PROJECT, 2021
** LabEntryState.hpp
** File description:
** LabEntryState
*/

#ifndef LabEntryState_H_
#define LabEntryState_H_

#include <stack>
#include <memory>
#include "StateBase.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../WorldObject.h"
#include "../Animation.h"
#include "../CollidableBox.h"
#include "../PlayerController.h"
#include "../EntityParser.h"



namespace State 
{
    class LabEntryState : public StateBase 
    {
        class LabEntry
        {
            public:
                LabEntry(float time, const sf::Texture& back);
                LabEntry(float time, const sf::Texture& back, const sf::SoundBuffer& sound);

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
            LabEntryState (Application& application);

            void input(const sf::Event& e) override;
            void input() override;
            void update(float dt) override;
            void draw() override;
        private:
            Objects::CollidableBox _box;
            std::unique_ptr<WorldObject::WorldLoader> world;
            sf::RectangleShape m_animSprite;
            Animation m_anim;
            PlayerController player;
            std::vector<LabEntry>  m_labEntry;
            sf::RectangleShape  m_fadeSprite;
            SplashState         m_currSplashState   = SplashState::Enter;
            int                 m_currAlphaValue    = 255;
            std::unique_ptr<sf::View> m_viewPort;
    };
}

#endif /* !LabEntryState_H_ */