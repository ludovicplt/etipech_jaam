#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <stack>

#include "ResourceManagers/ResourceHolder.h"
#include "States/StateBase.h"

class Application
{
    public:
        Application();

        void runMainLoop();

        const ResourceHolder& getResources() const;

        void setStatePlayerPos(sf::Vector2<float> pos) {
            m_states.top()->setPlayerPos(pos);
        }
        void pushState(std::unique_ptr<State::StateBase> state);
        void popState ();

    private:
        ResourceHolder m_resourceHolder;

        std::stack<std::unique_ptr<State::StateBase>> m_states;
};

#endif // APPLICATION_H_INCLUDED
