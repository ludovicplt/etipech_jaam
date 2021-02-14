//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_ICOLLIDABLE_H
#define MYPROJECT_ICOLLIDABLE_H

#include <SFML/Graphics.hpp>

class ICollidable {
public:
    sf::Rect<float> pos = {0, 0, 0, 0};
    bool isColliding = true;

    virtual void draw() const = 0;
    virtual void update() = 0;

    inline virtual sf::Rect<float> getPos() const
    {
        return pos;
    }

    inline virtual bool collides(const sf::Rect<float> &obj) const
    {
        return getPos().intersects(obj);
    }

    inline virtual bool collides(const sf::Rect<int> &obj) const
    {
        return collides(static_cast<sf::Rect<float>>(obj));
    }

    inline virtual bool collides(const ICollidable &collidable) const
    {
        return collides(collidable.getPos());
    }

    inline virtual bool collides(const sf::Vector2<float> &obj) const
    {
        return getPos().contains(obj);
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
        return getPos().contains(x, y);
    }

    inline virtual float getMaxDstLeft(const sf::Rect<float> &obj, float maxDst)
    {
        float newMaxDst = obj.left - (getPos().left + getPos().width);
        return maxDst < newMaxDst ? maxDst : newMaxDst;
    }

    inline virtual float getMaxDstRight(const sf::Rect<float> &obj, float maxDst)
    {
        float newMaxDst = getPos().left - (obj.left + obj.width);
        return maxDst < newMaxDst ? maxDst : newMaxDst;
    }

    inline virtual float getMaxDstUp(const sf::Rect<float> &obj, float maxDst)
    {
        float newMaxDst = obj.top - (getPos().top + getPos().height);
        return maxDst < newMaxDst ? maxDst : newMaxDst;
    }

    inline virtual float getMaxDstDown(const sf::Rect<float> &obj, float maxDst)
    {
        float newMaxDst = getPos().top - (obj.top + obj.height);
        return maxDst < newMaxDst ? maxDst : newMaxDst;
    }

};


#endif //MYPROJECT_ICOLLIDABLE_H
