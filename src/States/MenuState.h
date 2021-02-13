//
// Created by huntears on 2/13/21.
//

#ifndef MYPROJECT_MENUSTATE_H
#define MYPROJECT_MENUSTATE_H

#include <stack>
#include <memory>

#include "StateBase.h"

namespace State {
    class Menu : public StateBase {
    public:
        Menu (Application& application);

        void input  (const sf::Event& e);
        void input  ();
        void update (float dt);
        void draw   ();

    private:
        enum chosenOption {
            play,
            option,
            quit
        };

        chosenOption _selected = chosenOption::play;
        sf::Text _gameTitle;
        sf::RectangleShape _playButton;
        sf::RectangleShape _optionButton;
        sf::RectangleShape _quitButton;

        void switchOptionUp();
        void switchOptionDown();
        void handleLeftClick();
        void executeButton(chosenOption option);
        void executeButton();
        void handleMouseMoved();
        bool mouseIntersectsWithRectangle(const sf::RectangleShape &shape, const sf::Vector2f &cursorPos) const ;
    };
}


#endif //MYPROJECT_MENUSTATE_H
