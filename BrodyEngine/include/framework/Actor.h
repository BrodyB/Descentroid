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
        virtual void BeginPlay();
        virtual void Tick(float deltaTime);
        virtual void Render2D();
        virtual void Render3D();

    protected:
        Vector3 m_Position;

    private:
        const std::string m_Name;
        World* m_OwningWorld;
        bool m_BeganPlay{false};
    };
}