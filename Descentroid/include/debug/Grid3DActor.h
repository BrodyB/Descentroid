#pragma once

#include "framework/Actor.h"

namespace Descentroid
{
    class Grid3DActor : public BrodyEngine::Actor
    {
    public:
        Grid3DActor(BrodyEngine::World* owningWorld);
        virtual void Render2D() override;
        virtual void Render3D() override;

    private:
        int16_t halfSize{ 8 };
        float spacing{ 1.f };
    };
}