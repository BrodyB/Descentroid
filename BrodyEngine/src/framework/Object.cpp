#include "framework/Core.h"
#include "framework/Object.h"

namespace BrodyEngine
{
    Object::Object()
        : m_IsPendingDestroy{ false }
    {
    }

    Object::~Object()
    {
        PRINT("Object Destroyed");
    }

    void Object::Destroy()
    {
        m_IsPendingDestroy = true;
    }
}