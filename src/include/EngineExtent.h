//
// Created by echo_ on 2023-07-30.
//

#pragma once
#include <cstdint>
namespace engine{
    struct Extent2D{
        uint32_t Width;
        uint32_t Height;
    };

    struct Extent3D{
        uint32_t X;
        uint32_t Y;
        uint32_t Z;
    };
}
