#include "csv.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EntityParser.h"
#include <string>

namespace Entity {
    void EntityObject::SetPos(const float x, const float y)
    {
        this->myEntity.pos.x = x;
        this->myEntity.pos.y = y;
    }

    const sf::Vector2f EntityObject::getPos(void) const
    {
        return (this->myEntity.pos);
    }
            
    void EntityObject::SetIsCollidable(const bool IsCollidable)
    {
        this->myEntity.IsCollidable = IsCollidable;
    }

    const bool EntityObject::getIsCollidable(void) const
    {
        return (this->myEntity.IsCollidable);
    }

    void EntityObject::SetSpeech(const std::string &Speech)
    {
        this->myEntity.Speech = Speech;
    }

    const std::string EntityObject::GetSpeech(void) const
    {
        return (this->myEntity.Speech);
    }

    void EntityObject::SetName(const std::string &Name)
    {
        this->myEntity.Name = Name;
    }

    const std::string EntityObject::GetName(void) const
    {
        return (this->myEntity.Name);
    }

    void Pnj::Display(void)
    {
        for (int i = 0; i < myPnj.size(); i++) {
            std::cout << "Speech: \"" << this->myPnj[i].Speech << "\" x: " << this->myPnj[i].pos.x << " y: " << this->myPnj[i].pos.y << " IsCollidable: " << this->myPnj[i].IsCollidable << std::endl;
        }
    }
}