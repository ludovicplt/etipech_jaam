//
// Created by huntears on 2/13/21.
//

#include "PlayerController.h"

bool State::PlayerController::move(Direction direction)
{
    // TODO
    // Use ICollidable
}

void State::PlayerController::input(const sf::Event &e)
{
    switch (e.key.code) {
        case sf::Keyboard::Up:
            move(Direction::up);
            break;
        case sf::Keyboard::Right:
            move(Direction::right);
            break;
        case sf::Keyboard::Left:
            move(Direction::left);
            break;
        case sf::Keyboard::Down:
            move(Direction::down);
            break;
        default:
            break;
    }

}

void State::PlayerController::input()
{}

void State::PlayerController::update(float dt)
{
    // TODO
}

void State::PlayerController::draw()
{
    // TODO
}
