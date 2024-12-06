cmake_minimum_required(VERSION 3.28.3) # FetchContent is available in 3.11+

project(Descentroid
    VERSION 0.0.1
    LANGUAGES C CXX
)

set(ENGINE_TARGET_NAME BrodyEngine)
set(GAME_TARGET_NAME Descentroid)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(${ENGINE_TARGET_NAME})
# add_subdirectory(${GAME_TARGET_NAME})