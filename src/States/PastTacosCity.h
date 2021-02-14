#ifndef MYPROJECT_PASTTACOSCITY_H
#define MYPROJECT_PASTTACOSCITY_H

#include "StateBase.h"
#include "../PlayerController.h"
#include "../CollidableBox.h"
#include "../WorldObject.h"

namespace State {
    class PastTacosCity : public StateBase {
    private:
        PlayerController player;
        Objects::CollidableBox _Box;
        std::unique_ptr<WorldObject::WorldLoader> world;
    public:
        std::unique_ptr<sf::View> viewPort;
        PastTacosCity(Application& app);

        void input(const sf::Event& e);
        void input();
        void update(float dt);
        void draw();
    };
}

#endif