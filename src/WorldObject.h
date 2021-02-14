#ifndef WORLDOBJECT_H_INCLUDED
#define WORLDOBJECT_H_INCLUDED

#include "csv.h"
#include "ICollidable.h"
#include <string>
#include "csv.h"
#include "States/StateBase.h"
#include "ResourceManagers/TextureManager.h"
#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include "Application.h"

namespace WorldObject {
    class WorldItem {
        public:
            struct WorldEntity
            {
                std::string name;
                sf::Rect<float> rect;
                sf::Sprite *sprite;
                int IsCollideable;
                float SpriteSize;
            };
        private:
            struct WorldEntity myWorldItem;
        public:
            WorldItem(void) : myWorldItem({"", {0, 0, 0, 0}, NULL, false})
            {}
    };

    class WorldLoader : public WorldItem, public State::StateBase {
        private:
            std::vector<WorldItem::WorldEntity> _map;
        public:

            void DisplayInfo(void);

            WorldLoader(std::string filename, Application& application) :
                    WorldItem(), StateBase(application)
            {
                unsigned int tmpId;
                WorldItem::WorldEntity tmp;
                io::CSVReader<8> in(filename);
                in.read_header(io::ignore_extra_column, "Name", "PosX", "PosY", "SizeX", "SizeY", "SpriteSize", "Sprite", "Collidable");
                while (in.read_row(tmp.name,
                                   tmp.rect.left, tmp.rect.top, tmp.rect.width, tmp.rect.height,
                                   tmp.SpriteSize,
                                   tmpId,
                                   tmp.IsCollideable))
                {
                    if (tmpId != 999) {
                        tmp.sprite = new sf::Sprite;
                        tmp.sprite->setTexture(getTexture(static_cast<TextureID>(tmpId)));
                        tmp.sprite->setPosition(tmp.rect.left, tmp.rect.top);
                        tmp.sprite->setScale(tmp.SpriteSize, tmp.SpriteSize);
                    }
                    _map.push_back(tmp);
                }
            }

            const size_t getMapSize(void) const
            {
                return (_map.size());
            }

            const bool getIsCollidable(int i) const
            {
                return (_map[i].IsCollideable);
            }

            const sf::Sprite *getSprite(int i) const
            {
                return (_map[i].sprite);
            }

            const sf::Rect<float> getRect(int i) const
            {
                return (_map[i].rect);
            }

            void input() {};
            void update(float dt) {};
            void input(const sf::Event &e) {};
            void draw() {};
    };
}

#endif