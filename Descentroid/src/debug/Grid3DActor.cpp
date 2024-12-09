#include "framework/Core.h"
#include "debug/Grid3DActor.h"
#include "raylib.h"

namespace Descentroid
{
    Grid3DActor::Grid3DActor(BrodyEngine::World* owningWorld)
        : Actor{owningWorld}
    {
        m_Position = (Vector3){ 0.f, 0.f, 5.f };
    }

    void Grid3DActor::Render3D()
    {
        for (int x = -halfSize; x < halfSize; ++x)
        {
            for (int y = -halfSize; y < halfSize; ++y)
            {
                for (int z = -halfSize; z < halfSize; ++z)
                {
                    DrawCube(
                        (Vector3){
                            x * spacing + m_Position.x,
                            y * spacing + m_Position.y,
                            z * spacing + m_Position.z },
                        0.1f, 0.1f, 0.1f,
                        BLACK
                    );
                }
            }
        }
    }
}