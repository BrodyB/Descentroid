#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //Release Build
    return "assets/";
#else
    return "/home/brody/Documents/Projects/Descentroid/Descentroid/assets/";
#endif
}
