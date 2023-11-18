#pragma once

#include <volk.h>
#include <VkBootstrap.h>

struct RendererDevices{
    VkPhysicalDevice PhysicalDevice;
    VkDevice DeviceAbstraction;
    VkSurfaceKHR Surface;
};