#pragma once

#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include "raylib.h"

namespace BrodyEngine
{
    // A macro
    #define PRINT(M, ...) printf(M "\n", ##__VA_ARGS__)
    #define PRINTH(H, M, ...) printf("///> %f " H " / " M "\n", GetTime(), ##__VA_ARGS__)

    // Give a nickname to a generic unique pointer
    template<typename T>
    using unique = std::unique_ptr<T>;

    template<typename T>
    using shared = std::shared_ptr<T>;

    template<typename T>
    using weak = std::weak_ptr<T>;

    template<typename T>
    using List = std::vector<T>;

    template<typename keyType, typename valueType, typename Pr = std::less<keyType>>
    using Map = std::map<keyType, valueType, Pr>;

    template<typename keyType, typename valueType, typename hasher = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valueType, hasher>;
}