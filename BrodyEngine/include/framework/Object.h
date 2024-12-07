#pragma once

namespace BrodyEngine
{
    class Object
    {
    public:
        Object();
        virtual ~Object();

        void Destroy();
        bool IsPendingDestroy() const { return m_IsPendingDestroy; }
    private:
        bool m_IsPendingDestroy;
    };
}