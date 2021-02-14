//
// Created by alexis on 2/14/21.
//

#ifndef MYPROJECT_COLLIDABLEBOX_H
#define MYPROJECT_COLLIDABLEBOX_H

#include <SFML/Graphics.hpp>
#include "ICollidable.h"
#include "Display.h"

namespace Objects
{
    class CollidableBox : public ICollidable {
    public:
        CollidableBox() : ICollidable()
        {
            
        }
        sf::RectangleShape box;
        void draw() const
        {
           // Display::draw(box);
        }

        inline void setBounds(sf::Rect<float> bounds)
        {
            box.setPosition(bounds.left, bounds.top);
            box.setSize({ bounds.width, bounds.height });
        }

        void update()
        {

        }

        inline virtual sf::Rect<float> getPos() const override
        {
            return box.getGlobalBounds();
        }
    };
}


#endif //MYPROJECT_COLLIDABLEBOX_H
