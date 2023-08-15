//
// Created by echo_ on 2023-07-28.
//

#pragma once

#include <volk.h>
#include <VkBootstrap.h>
struct RendererDevices{
    VkPhysicalDevice PhysicalDevice;
    VkDevice DeviceAbstraction;
    VkSurfaceKHR Surface;
};