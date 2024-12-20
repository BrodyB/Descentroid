#include "Vector3.h"

namespace BrodyEngine
{
    #pragma region Constructors
    Vector3::Vector3() {}

    Vector3::Vector3(float x, float y, float z)
        : x{x}, y{y}, z{z}
    {
    }

    Vector3::Vector3(const Vector3& original)
        : x{original.x}, y{original.y}, z{original.z}
    {
    }

    Vector3::Vector3(const raylib::Vector3& vector)
        : x{vector.x}, y{vector.y}, z{vector.z}
    {
    }
    #pragma endregion

    #pragma region Constants
    const Vector3 Vector3::ZERO = Vector3(0.f, 0.f, 0.f);
    const Vector3 Vector3::ONE = Vector3(1.f, 1.f, 1.f);
    const Vector3 Vector3::LEFT = Vector3(-1.f, 0.f, 0.f);
    const Vector3 Vector3::RIGHT = Vector3(1.f, 0.f, 0.f);
    const Vector3 Vector3::UP = Vector3(0.f, 1.f, 0.f);
    const Vector3 Vector3::DOWN = Vector3(0.f, -1.f, 0.f);
    const Vector3 Vector3::FORWARD = Vector3(0.f, 0.f, 1.f);
    const Vector3 Vector3::BACK = Vector3(0.f, 0.f, -1.f);
    #pragma endregion

    Vector3& Vector3::MoveTowards(const Vector3 &target, float maxDistance)
    {
        float dx = target.x - x;
        float dy = target.y - y;
        float dz = target.z - z;
        float dl = (dx * dx) + (dy * dy) + (dz * dz);

        if ((dl == 0.f) || ((maxDistance >= 0) && (dl <= maxDistance*maxDistance)))
        {
            x = target.x;
            y = target.y;
            z = target.z;
            return *this;
        }

        float dist = sqrtf(dl);

        x += dx / dist * maxDistance;
        y += dy / dist * maxDistance;
        z += dz / dist * maxDistance;

        return *this;
    }

    raylib::Vector3 Vector3::ToRayVector3(const Vector3 &vector)
    {
        raylib::Vector3 output(vector.x, vector.y, vector.z);
        return output;
    }

    Vector3 Vector3::Normalized(const Vector3 &vector)
    {
        return Vector3(vector).Normalize();
    }

    Vector3 Vector3::Lerp(const Vector3& from, const Vector3& to, float target)
    {
        Vector3 output;

        output.x = from.x + target * (to.x - from.x);
        output.y = from.y + target * (to.y - from.y);
        output.z = from.z + target * (to.z - from.z);

        return output;
    }
}