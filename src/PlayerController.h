//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_PLAYERCONTROLLER_H
#define MYPROJECT_PLAYERCONTROLLER_H

#include <list>

#include "ICollidable.h"
#include "States/StateBase.h"

namespace State {
    class PlayerController : public StateBase {
    public:
        enum Direction {
            up,
            down,
            right,
            left
        };
    private:
        Direction currentdirection;
    public:
        PlayerController();

        std::list<ICollidable> collideList;

        bool move(Direction direction);

        void input(const sf::Event& e);
        void input();
        void update(float dt);
        void draw();
    };
}


#endif //MYPROJECT_PLAYERCONTROLLER_H
