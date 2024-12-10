#pragma once

#include "framework/Core.h"
#include "framework/Actor.h"

namespace Descentroid
{
    class World;
    class PlayerShip : public BrodyEngine::Actor
    {
    public:
        PlayerShip(BrodyEngine::World* owningWorld);
        virtual void BeginPlay() override;
        virtual void Tick(float deltaTime) override;
        virtual void Render2D() override;

        void SetCameraReference(Camera3D* camera);
        void SetMovementActive(bool active);
    
    private:
        Matrix m_Transform;
        Vector3 m_Velocity{ 0, 0, 0 };
        Vector3 m_AngularVelocity{ 0, 0, 0};
        float m_Acceleration{ 0.4f };
        float m_Torque{ 25.0f };
        float m_Drag{ 0.05f };
        float m_AngularDrag{ 1.f };
        bool m_MoveInputActive{ true };
        Camera3D* m_Camera{ nullptr };

        void ProcessInput(float deltaTime);
    };
}