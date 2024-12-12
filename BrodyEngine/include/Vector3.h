#pragma once
#include <stddef.h>

namespace BrodyEngine
{
    class Vector3
    {
    public:
        float x;
        float y;
        float z;

        Vector3();
        Vector3(float x, float y, float z);
        Vector3(Vector3& original);

        Vector3 operator+(const Vector3 vector) const;
        Vector3 operator-(const Vector3 vector) const;
        Vector3 operator*(float scalar) const;
        Vector3 operator/(float scalar) const;

        Vector3& Vector3::operator+=(const Vector3& vector);
        Vector3& Vector3::operator-=(const Vector3& vector);
        Vector3 operator-() const;
        Vector3& operator*=(float scalar);
        Vector3& operator/=(float scalar);

        bool operator==(const Vector3 vector) const;
        bool operator!=(const Vector3 vector) const;

        float& operator[](size_t i);
        float operator[](size_t i) const;

        Vector3 Length();
        Vector3 Normalize();

        static const Vector3 ZERO;
        static const Vector3 ONE;
        static const Vector3 LEFT;
        static const Vector3 RIGHT;
        static const Vector3 UP;
        static const Vector3 DOWN;
        static const Vector3 FORWARD;
        static const Vector3 BACK;

        static Vector3 Normalized(Vector3 vector);
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
    }

    inline Vector3& Vector3::operator-=(const Vector3& vector)
    {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
    }

    inline Vector3& Vector3::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
    }

    inline Vector3& Vector3::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
    }


    inline bool Vector3::operator==(const Vector3 vector) const
    {
        return x == vector.x && y == vector.y && z == vector.z;
    }

    inline bool Vector3::operator!=(const Vector3 vector) const
    {
        return x != vector.x || y != vector.y || z != vector.z;
    }


    float& Vector3::operator[](size_t i)
    {
        switch (i)
        {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default: throw "Out of bounds!";
        }
    }

    float Vector3::operator[](size_t i) const
    {
        return (*const_cast<Vector3*>(this))[i];
    }
    #pragma endregion

    #pragma region Modification Methods
    inline Vector3 Vector3::Normalize()
    {
        return *this;
    }
    #pragma endregion
}