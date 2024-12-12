#pragma once
#include <stddef.h>
#include <math.h>

namespace BrodyEngine
{
    class Vector3
    {
    public:
        float x{0.f};
        float y{0.f};
        float z{0.f};

        Vector3();
        Vector3(float x, float y, float z);
        Vector3(Vector3& original);

        Vector3 operator+(const Vector3 vector) const;
        Vector3 operator-(const Vector3 vector) const;
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;

        Vector3& operator+=(const Vector3& vector);
        Vector3& operator-=(const Vector3& vector);
        Vector3 operator-() const;
        Vector3& operator*=(float scalar);
        Vector3& operator/=(float scalar);

        bool operator==(const Vector3 vector) const;
        bool operator!=(const Vector3 vector) const;

        float Length();
        float Distance(const Vector3& other);
        Vector3 Normalize();
        Vector3 CrossProduct(const Vector3& vector);
        float DotProduct(const Vector3& other);
        Vector3& MoveTowards(const Vector3& vector, float maxDistance);
        Vector3& Reflect(const Vector3& normal);

        static const Vector3 ZERO;
        static const Vector3 ONE;
        static const Vector3 LEFT;
        static const Vector3 RIGHT;
        static const Vector3 UP;
        static const Vector3 DOWN;
        static const Vector3 FORWARD;
        static const Vector3 BACK;

        static Vector3 Normalized(Vector3 vector);
        static Vector3 Lerp(Vector3 from, Vector3 to, float target);
        static float Angle(const Vector3& v1, const Vector3& v2);
    };

    #pragma region Inline Operations
    inline Vector3 Vector3::operator+(const Vector3 vector) const
    {
        return Vector3(x + vector.x, y + vector.y, z + vector.z);
    }

    inline Vector3 Vector3::operator-(const Vector3 vector) const
    {
        return Vector3(x - vector.x, y - vector.y, z - vector.z);
    }

    inline Vector3 Vector3::operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    inline Vector3 Vector3::operator/(float scalar) const
    {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    inline Vector3 Vector3::operator-() const
    {
        return Vector3(-x, -y, -z);
    }

    inline Vector3& Vector3::operator+=(const Vector3& vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        return *this;
    }

    inline Vector3& Vector3::operator-=(const Vector3& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        return *this;
    }

    inline Vector3& Vector3::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    inline Vector3& Vector3::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }


    inline bool Vector3::operator==(const Vector3 vector) const
    {
        return x == vector.x && y == vector.y && z == vector.z;
    }

    inline bool Vector3::operator!=(const Vector3 vector) const
    {
        return x != vector.x || y != vector.y || z != vector.z;
    }
    #pragma endregion

    #pragma region Properties and Modifications
    inline float Vector3::Length()
    {
        return sqrtf(x*x + y*y + z*z);
    }

    inline float Vector3::Distance(const Vector3& other)
    {
        float nx = other.x - x;
        float ny = other.y - y;
        float nz = other.z - z;

        return sqrt(nx*nx + ny*y + nz*nz);
    }

    inline Vector3 Vector3::Normalize()
    {
        if (Length() != 0.f)
        {
            float inverse = 1.0f/Length();
            x *= inverse;
            y *= inverse;
            z *= inverse;
        }

        return *this;
    }

    inline Vector3 Vector3::CrossProduct(const Vector3& vector)
    {
        return Vector3(
            y * vector.z - z * vector.y,
            z * vector.x - x * vector.z,
            x * vector.y - y * vector.x
        );
    }

    inline float Vector3::DotProduct(const Vector3 &other)
    {
        return x * other.x + y * other.y + z * other.z;
    }

    inline Vector3& Vector3::Reflect(const Vector3 &normal)
    {
        float dot = DotProduct(normal);

        x -= (2.f * normal.x) * dot;
        y -= (2.f * normal.y) * dot;
        z -= (2.f * normal.z) * dot;

        return *this;
    }
    #pragma endregion
}