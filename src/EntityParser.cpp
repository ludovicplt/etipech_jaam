#include "csv.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EntityParser.h"
#include <string>

namespace Entity {
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
}