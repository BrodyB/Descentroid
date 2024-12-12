#pragma once

#include "Vector3.h"

namespace BrodyEngine
{
    struct Ray
    {
        Vector3 origin;
        Vector3 direction;

        Ray() : origin{Vector3()}, direction{Vector3::FORWARD} {}
        Ray(Vector3 origin, Vector3 direction)
            : origin{origin}, direction{direction} {};
    };
}