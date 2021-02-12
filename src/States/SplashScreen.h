#ifndef SPLASH_SCREEN_H_INCLUDED
#define SPLASH_SCREEN_H_INCLUDED

#include <stack>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "StateBase.h"


namespace State
{
    class SplashScreen : public StateBase
    {
        class Splash
        {
            public:
                Splash(float time, const sf::Texture& splash);
                Splash(float time, const sf::Texture& splash, const sf::SoundBuffer& sound);

                void start();
                void draw();
                bool isOver();

            private:
                float               m_time;
                sf::RectangleShape  m_sprite;
                sf::Clock           m_clock;
                std::unique_ptr<sf::Sound> m_sound;
        };

        enum class SplashState
        {
            Enter,
            Active,
            Exiting
        };

        public:
            SplashScreen (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:
            std::stack<Splash>  m_splashes;
            sf::RectangleShape  m_fadeSprite;
            SplashState         m_currSplashState   = SplashState::Enter;
            int                 m_currAlphaValue    = 255;
    };
}

#endif // SPLASH_SCREEN_H_INCLUDED
