//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_ICOLLIDABLE_H
#define MYPROJECT_ICOLLIDABLE_H

#include <SFML/Graphics.hpp>

class ICollidable {
public:
    sf::Rect<float> pos;
    bool isColliding;

    virtual void draw() const = 0;
    virtual void update() = 0;

    inline virtual bool collides(const sf::Rect<float> &obj) const
    {
        return pos.intersects(obj);
    }

    inline virtual bool collides(const sf::Rect<int> &obj) const
    {
        return collides(static_cast<sf::Rect<float>>(obj));
    }

    inline virtual bool collides(const ICollidable &collidable) const
    {
        return collides(collidable.pos);
    }

    inline virtual bool collides(const sf::Vector2<float> &obj) const
    {
        return pos.contains(obj);
    }

    inline virtual bool collides(const sf::Vector2<int> &obj) const
    {
        return collides(obj.x, obj.y);
    }

    inline virtual bool collides(int x, int y) const
    {
        return collides(static_cast<float>(x), static_cast<float>(y));
    }

    inline virtual bool collides(float x, float y) const
    {
        return pos.contains(x, y);
    }

};


#endif //MYPROJECT_ICOLLIDABLE_H
