//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_SFMLEXTENSION_H
#define MYPROJECT_SFMLEXTENSION_H

#include <iostream>

#include <SFML/Graphics.hpp>

template<typename T>
inline sf::Rect<T> operator +(const sf::Rect<T>& left, const sf::Rect<T>& right)
{
    sf::Rect<T> toReturn(left.left + right.left,
                       left.top + right.top,
                       left.width + right.width,
                       left.height + right.height);
    return toReturn;
}

template<typename T>
inline std::ostream &operator <<(std::ostream &os, const sf::Rect<T> &obj)
{
    os << "<";
    os << obj.left;
    os << ", ";
    os << obj.top;
    os << ", ";
    os << obj.width;
    os << ", ";
    os << obj.height;
    os << ">";
    return os;
}

#endif //MYPROJECT_SFMLEXTENSION_H
