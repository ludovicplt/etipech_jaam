#include "csv.h"
#include <SFML/Graphics.hpp>
#include <string>

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
            void SetPos(const float x, const float y);
            const sf::Vector2f getPos(void) const;
            void SetIsCollidable(const bool IsCollidable);
            const bool getIsCollidable(void) const;
            void SetSpeech(const std::string &Speech);
            const std::string GetSpeech(void) const;
            void SetName(const std::string &Name);
            const std::string GetName(void) const;
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
                io::CSVReader<5> in("info.csv");
                in.read_header(io::ignore_extra_column, "Name", "Position_x", "Position_y", "IsCollidable", "Speech");

                while (in.read_row(tmp.Name, tmp.pos.x, tmp.pos.y, tmp.IsCollidable, tmp.Speech))
                    myPnj.push_back(tmp);
            }
    };
}
     