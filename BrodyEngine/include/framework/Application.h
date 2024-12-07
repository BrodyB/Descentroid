#pragma once
#include <string>
#include "raylib.h"

namespace BrodyEngine
{
    class Application
    {
    public:
        Application(unsigned int width, unsigned int height, std::string title);
        void Run();
        ~Application();

    private:
        void StartInternal();
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Start();
        virtual void Tick(float deltaTime);
        virtual void Render();

        bool m_Started{false};
        float m_TargetFrameRate;
        unsigned int m_Width{800};
        unsigned int m_Height{600};
        std::string m_Title;
    };
}