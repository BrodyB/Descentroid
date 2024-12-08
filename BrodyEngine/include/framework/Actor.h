#pragma once

#include <string>
#include "framework/Core.h"
#include "framework/Object.h"
#include "raylib.h"

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
        void RenderInternal();
        virtual void BeginPlay() = 0;
        virtual void Tick(float deltaTime) = 0;
        virtual void Render() = 0;

    private:
        const std::string m_Name;
        World* m_OwningWorld;
        Vector3 m_Position;
        bool m_BeganPlay{false};
    };
}