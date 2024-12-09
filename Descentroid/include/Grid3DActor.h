#pragma once

#include "framework/Actor.h"

namespace Descentroid
{
    class Grid3DActor : public BrodyEngine::Actor
    {
    public:
        virtual void Render() override;

    private:
        int16_t halfSize{ 32 };
        float spacing{ 5.f };
    }
}