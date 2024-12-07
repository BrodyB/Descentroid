#pragma once

#include "framework/Core.h"
#include "framework/Object.h"
#include <string>

namespace BrodyEngine
{
    class World;

    class Actor : public Object
    {
    public:
        Actor(World* owningWorld);
        Actor(World* owningWorld, std::string name);
        virtual ~Actor();

        const std::string& name() const { return m_Name; }

        void BeginPlayInternal();
        void TickInternal(float deltaTime);
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);

    private:
        const std::string m_Name;
        World* m_OwningWorld;
        bool m_BeganPlay{false};
    };
}