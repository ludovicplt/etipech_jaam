#ifndef PLAYING_STATE_H_INCLUDED
#define PLAYING_STATE_H_INCLUDED

#include "StateBase.h"

#include "../Animation.h"
#include "../PlayerController.h"

namespace State
{
    class Playing : public StateBase
    {
        public:
            Playing (Application& application);

            void input  (const sf::Event& e);
            void input  ();
            void update (float dt);
            void draw   ();

        private:
            sf::RectangleShape  m_animSprite;
            Animation           m_anim;
            sf::Text            m_text;
            PlayerController player;
    };
}

#endif // PLAYING_STATE_H_INCLUDED
