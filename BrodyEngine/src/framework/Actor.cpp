#include "framework/Actor.h"
#include "Actor.h"

namespace BrodyEngine
{
    Actor::Actor(World *owningWorld)
    {
        Actor(owningWorld, "[ACTOR]");
    }

    Actor::Actor(World *owningWorld, std::string name)
        : m_OwningWorld{owningWorld},
        m_Name{ name },
        m_BeganPlay{false}
    {
    }

    Actor::~Actor()
    {
    }

    void Actor::BeginPlayInternal()
    {
        if (!m_BeganPlay)
        {
            m_BeganPlay = true;
            BeginPlay();
        }
    }

    void Actor::TickInternal(float deltaTime)
    {
        Tick(deltaTime);
    }

    void Actor::BeginPlay()
    {
    }

    void Actor::Tick(float deltaTime)
    {
    }
}


