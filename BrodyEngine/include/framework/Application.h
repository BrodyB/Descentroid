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

    protected:
        double lifetime() const { return m_Lifetime; }
        void SetClearColor(Color color);

        Color m_ClearColor{ BLACK };

    private:
        void StartInternal();
        void TickInternal(float deltaTime);
        void RenderInternal();

        virtual void Start() = 0;
        virtual void Tick(float deltaTime) = 0;
        virtual void Render() = 0;

        bool m_Started{false};
        float m_TargetFrameRate;
        unsigned int m_Width{800};
        unsigned int m_Height{600};
        std::string m_Title;
        double m_Lifetime;
    };
}