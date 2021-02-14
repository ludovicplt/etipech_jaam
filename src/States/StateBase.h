#ifndef STATE_BASE_H_INCLUDED
#define STATE_BASE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../ResourceManagers/ResourceHolder.h"

class Application;

namespace State
{
    class StateBase
    {
        public:
            StateBase(Application& app);
            virtual ~StateBase() {}

            virtual void input  (const sf::Event& e)    = 0;
            virtual void input  ()                      = 0;
            virtual void update (float dt)              = 0;
            virtual void draw   ()                      = 0;

            virtual void setPlayerPos(sf::Vector2<float> pos) {}

        protected:
            const sf::Texture&      getTexture (TextureID id) const;
            const sf::Font&         getFont    (FontID    id) const;
            const sf::SoundBuffer&  getSound   (SoundID    id) const;

        protected:
            Application* m_p_application;

    };
}

#endif // STATE_BASE_H_INCLUDED
