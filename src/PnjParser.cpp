#include "csv.h"
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Entity {
    class EntityObject {
        public:
            struct Entity {
                sf::Vector2f pos;
                int IsCollidable;
                std::string Speech;
                std::string Name;
            };
        private:
            struct Entity myEntity;
        public:
            void SetPos(const float x, const float y)
            {
                this->myEntity.pos.x = x;
                this->myEntity.pos.y = y;
            }

            const sf::Vector2f getPos(void) const
            {
                return (this->myEntity.pos);
            }
            
            void SetIsCollidable(const bool IsCollidable)
            {
                this->myEntity.IsCollidable = IsCollidable;
            }

            const bool getIsCollidable(void) const
            {
                return (this->myEntity.IsCollidable);
            }

            void SetSpeech(const std::string Speech)
            {
                this->myEntity.Speech = Speech;
            }

            const std::string GetSpeech(void) const
            {
                return (this->myEntity.Speech);
            }

            void SetName(const std::string Name)
            {
                this->myEntity.Name = Name;
            }

            const std::string GetName(void) const
            {
                return (this->myEntity.Name);
            }
            EntityObject(void) {}
    };

    class Pnj : public EntityObject {
        private:
            std::vector<EntityObject::Entity> myPnj;
        public:
            void Display(void)
            {
                for (int i = 0; i < myPnj.size(); i++) {
                    std::cout << "Speech: \"" << this->myPnj[i].Speech << "\" x: " << this->myPnj[i].pos.x << " y: " << this->myPnj[i].pos.y << " IsCollidable: " << this->myPnj[i].IsCollidable << std::endl;
                }
            }

            Pnj(std::string filename)
            {
                EntityObject::Entity tmp;
                io::CSVReader<5> in("info.csv");
                in.read_header(io::ignore_extra_column, "Name", "Position_x", "Position_y", "IsCollidable", "Speech");

                while (in.read_row(tmp.Name, tmp.pos.x, tmp.pos.y, tmp.IsCollidable, tmp.Speech))
                    myPnj.push_back(tmp);
            }
    };
}
                /*
                State::Pnj PnjTmp = {0};

                io::CSVReader<5> in(filename);
                in.read_header(io::ignore_extra_column, "Name", "Position_x", "Position_y", "IsCollidable", "Text");
                while (in.read_row(name, pos.x, pos.y, IsCollidable, speech))
                */

int main(void)
{
    Entity::Pnj myPnj("info.csv");

    myPnj.Display();
}
