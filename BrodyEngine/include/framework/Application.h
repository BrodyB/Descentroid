#pragma once

namespace BrodyEngine
{
    class Application
    {
    public:
        Application(unsigned int width, unsigned int height, const char* title);

    private:
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Tick(float deltaTime);
        virtual void Render();

        float m_TargetFrameRate;
    };
}