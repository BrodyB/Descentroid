#pragma once

#include "Vector3.h"
#include "raylib-cpp.hpp"

namespace BrodyEngine
{
    class Ray
    {
    public:
        Vector3 origin{};
        Vector3 direction{};

        Ray() : origin{Vector3()}, direction{Vector3::FORWARD} {}
        Ray(Vector3 origin, Vector3 direction)
            : origin{origin}, direction{direction} {};

        static raylib::Ray ToRayRay(const Ray& ray)
        {
            raylib::Ray output(
                Vector3::ToRayVector3(ray.origin),
                Vector3::ToRayVector3(ray.direction)
            );

            return output;
        }
    };
}