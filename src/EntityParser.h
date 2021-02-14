#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED



#include "csv.h"
#include <SFML/Graphics.hpp>
#include <string>



namespace Entity {
    class EntityObject {
        public:
            struct Entity {
                sf::Rect<float> pos;
                std::string Speech;
                std::string Name;
            };
        private:
            struct Entity myEntity;
        public:
            void SetPos(const float x, const float y);
            const sf::Vector2f getPos(void) const;
            void SetIsCollidable(const bool IsCollidable);
            const bool getIsCollidable(void) const;
            void SetSpeech(const std::string &Speech);
            const std::string GetSpeech(void) const;
            void SetName(const std::string &Name);
            EntityObject(void) {}
    };

    class Pnj : public EntityObject {
        private:
            std::vector<EntityObject::Entity> myPnj;
        public:
            void Display(void);
            Pnj(std::string filename)
            {
                EntityObject::Entity tmp;
                io::CSVReader<6> in(filename);
                in.read_header(io::ignore_extra_column, "Name", "PosX", "PosY", "SizeX", "SizeY", "Speech");

                while (in.read_row(tmp.Name, tmp.pos.left, tmp.pos.top, tmp.pos.width, tmp.pos.height, tmp.Speech))
                    myPnj.push_back(tmp);
            }

            bool IsIntersecting(sf::Rect<float> r1, sf::Rect<float> r2)
            {
                return (r1.intersects(r2));
            }

            size_t getSize(void)
            {
                return (myPnj.size());
            }

            sf::FloatRect getPos(int i)
            {
                return (myPnj[i].pos);
            }

            const std::string &getSpeech(int i)
            {
                return (myPnj[i].Speech);
            }

            const std::string &getName(int i)
            {
                return (myPnj[i].Name);
            }
    };
}
#endif // ENTITY_H_INCLUDED

     