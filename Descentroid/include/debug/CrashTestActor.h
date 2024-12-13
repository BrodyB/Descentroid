#pragma once

#include "framework/Core.h"
#include "framework/Actor.h"
#include "Vector3.h"
#include "Ray.h"

#include "raylib.h"

namespace Descentroid
{
    class TestWorld;

    using BrodyEngine::Vector3;
    using BrodyEngine::Ray;

    class CrashTestActor : public BrodyEngine::Actor
    {
    public:
        CrashTestActor(BrodyEngine::World* owningWorld);
        virtual void Tick(float deltaTime) override;
        virtual void Render2D() override;
        virtual void Render3D() override;

    private:
        TestWorld* m_World{ nullptr };
        Vector3 m_Velocity;
        float m_Acceleration{ 0.6f };
        float m_Drag{ 0.1f };
        Ray m_ColRay{};
        Vector3 m_Rays[128];

        const Vector3 Up { Vector3::UP };
        const Vector3 Forward { Vector3::FORWARD };
        const Vector3 Right { Vector3::RIGHT };

        void ProcessInput(float deltaTime);
        void CheckForCollisions();
        void PerformMovement(float deltaTime);
        RayCollision GetCollisionSide();
    };
}