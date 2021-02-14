#include "Application.h"

#include <iostream>

#include "Display.h"
#include "Util/Random.h"

#include "States/SplashScreen.h"

#include "States/PastOffice.h"

namespace
{
    void calculateFPS()
    {
        static sf::Clock timer;
        static sf::Clock printTimer;
        static auto numFrames = 0;

        numFrames++;

        if (printTimer.getElapsedTime().asSeconds() >= 1.0f) {
            auto fps = (float)numFrames / timer.getElapsedTime().asSeconds();
            printTimer.restart();
            std::cout << "FPS : " << fps << std::endl;

            numFrames = 0;
            timer.restart();
        }
    }
}

Application::Application()
{
    Display::init();
    Random::init();

    pushState(std::make_unique<State::SplashScreen>(*this));
}

void Application::runMainLoop()
{
    sf::Clock c;

    pushState(std::make_unique<State::SplashScreen>(*this));
    while (Display::isOpen()) {
        auto dt = c.restart().asSeconds();

        Display::clear();

        m_states.top()->input   ();
        m_states.top()->update  (dt);
        m_states.top()->draw    ();

        Display::update         ();
        calculateFPS            ();

        Display::pollEvents(*m_states.top());
    }
}


const ResourceHolder& Application::getResources() const
{
    return m_resourceHolder;
}

void Application::pushState(std::unique_ptr<State::StateBase> state)
{
    m_states.push(std::move(state));
}

void Application::popState()
{
    m_states.pop();
}
