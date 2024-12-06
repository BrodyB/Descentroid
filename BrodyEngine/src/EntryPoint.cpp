#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
    BrodyEngine::Application* app = GetApplication();
    delete app;
}