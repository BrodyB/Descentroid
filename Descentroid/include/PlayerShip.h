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

        void SetMovementActive(bool active);
    
    private:
        bool m_MovementActive{ true };

    };
}