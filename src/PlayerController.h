//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_PLAYERCONTROLLER_H
#define MYPROJECT_PLAYERCONTROLLER_H

#include <list>

#include "ICollidable.h"
#include "States/StateBase.h"
#include "Animation.h"

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
        Direction currentdirection = right;
        sf::RectangleShape playerSprite;
        Animation playerUpAnim;
        Animation playerDownAnim;
        Animation playerRightAnim;
        Animation playerLeftAnim;
        const float speed = 2500.f;
        bool requestMove = false;
    public:
        PlayerController(Application &app);

        std::list<std::unique_ptr<ICollidable>> collideList;

        void move(Direction direction);
        void addCollidable(std::unique_ptr<ICollidable> collidable);

        void input(const sf::Event& e);
        void input();
        void update(float dt);
        void draw();
        sf::Rect<float> getPos();
        void setPos(sf::Vector2<float> pos);
        void setSize(sf::Vector2<float> size);

        void displayPos(void)
        {
            std::cout << "<" << getPos().left << ", " << getPos().top << ">" << std::endl;
        }
    };
}


#endif //MYPROJECT_PLAYERCONTROLLER_H
