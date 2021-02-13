#ifndef PAST2_CITY_H
#define PAST2_CITY_H

#include "StateBase.h"

namespace State
{
    class PastTacosCity : public StateBase
    {
    public:
        PastTacosCity (Application& application);

        void input  (const sf::Event& e);
        void input  ();
        void update (float dt);
        void draw   ();

    private:
        sf::Sprite m_alexandroFlioVehicle;
        sf::Sprite m_alexandroFlioSign;
        sf::Sprite m_background;
    };
}


#endif //PAST2_CITY_H
