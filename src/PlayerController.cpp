//
// Created by huntears on 2/13/21.
//

#include <iostream>

#include "Display.h"
#include "PlayerController.h"
#include "SFMLExtension.h"

State::PlayerController::PlayerController(Application &app) :
    StateBase(app)
{
    playerSprite.setTexture(&getTexture(TextureID::player));
    playerSprite.setSize({24, 62});
    playerSprite.setPosition({5, 600});

    const float timeBetweenSteps = 0.25;

    // Ugly, but it will do the job
    playerRightAnim.addFrame({0, 0, 12, 31}, timeBetweenSteps);
    playerRightAnim.addFrame({13, 0, 12, 31}, timeBetweenSteps);

    playerLeftAnim.addFrame({2 * 13, 0, 12, 31}, timeBetweenSteps);
    playerLeftAnim.addFrame({3 * 13, 0, 12, 31}, timeBetweenSteps);

    playerDownAnim.addFrame({4 * 13, 0, 12, 31}, timeBetweenSteps);
    playerDownAnim.addFrame({5 * 13, 0, 12, 31}, timeBetweenSteps);
    playerDownAnim.addFrame({6 * 13, 0, 12, 31}, timeBetweenSteps);

    playerUpAnim.addFrame({7 * 13, 0, 12, 31}, timeBetweenSteps);
    playerUpAnim.addFrame({8 * 13, 0, 12, 31}, timeBetweenSteps);
    playerUpAnim.addFrame({9 * 13, 0, 12, 31}, timeBetweenSteps);
}

void State::PlayerController::move(Direction direction)
{
    currentdirection = direction;
    requestMove = true;
}

void State::PlayerController::input(const sf::Event &e)
{
    if (e.type == sf::Event::MouseMoved)
        return;
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

void State::PlayerController::addCollidable(std::unique_ptr<ICollidable> collidable)
{
    collideList.push_back(std::move(collidable));
}

void State::PlayerController::update(float dt)
{
    // Movement
    if (requestMove) {
        float maxDst = speed * dt;
        for (auto &collider : collideList) {
            switch (currentdirection) {
                case Direction::up:
                    if (collider->collides(playerSprite.getGlobalBounds() + sf::Rect<float>(0, -maxDst, 0, 0)))
                        maxDst = collider->getMaxDstUp(playerSprite.getGlobalBounds(), maxDst);
                    break;
                case Direction::down:
                    if (collider->collides(playerSprite.getGlobalBounds() + sf::Rect<float>(0, maxDst, 0, 0)))
                        maxDst = collider->getMaxDstDown(playerSprite.getGlobalBounds(), maxDst);
                    break;
                case Direction::left:
                    if (collider->collides(playerSprite.getGlobalBounds() + sf::Rect<float>(-maxDst, 0, 0, 0)))
                        maxDst = collider->getMaxDstLeft(playerSprite.getGlobalBounds(), maxDst);
                    break;
                case Direction::right:
                    if (collider->collides(playerSprite.getGlobalBounds() + sf::Rect<float>(maxDst, 0, 0, 0)))
                        maxDst = collider->getMaxDstRight(playerSprite.getGlobalBounds(), maxDst);
                    break;
            }
        }
        switch (currentdirection) {
            case Direction::up:
                playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2<float>(0, -maxDst));
                break;
            case Direction::down:
                playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2<float>(0, maxDst));
                break;
            case Direction::left:
                playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2<float>(-maxDst, 0));
                break;
            case Direction::right:
                playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2<float>(maxDst, 0));
                break;
        }
        requestMove = false;
    }

    // Animation
    switch (currentdirection) {
        case Direction::up:
            playerSprite.setTextureRect(playerUpAnim.getFrame());
            break;
        case Direction::down:
            playerSprite.setTextureRect(playerDownAnim.getFrame());
            break;
        case Direction::left:
            playerSprite.setTextureRect(playerLeftAnim.getFrame());
            break;
        case Direction::right:
            playerSprite.setTextureRect(playerRightAnim.getFrame());
            break;
    }
}

void State::PlayerController::draw()
{
    Display::draw(playerSprite);
    for (auto &collider : collideList) {
        collider->draw();
    }
}

sf::Rect<float> State::PlayerController::getPos(void)
{
    return (playerSprite.getGlobalBounds());
}

void State::PlayerController::setPos(sf::Vector2<float> pos)
{   
    playerSprite.setPosition(pos);
}

void State::PlayerController::setSize(sf::Vector2<float> size)
{
    playerSprite.setScale(size);
}