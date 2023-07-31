//
// Created by echo_ on 2023-07-28.
//
#pragma once
#include <volk.h>

namespace engine{
    struct RendererExternal{
        VkSurfaceKHR Surface;

    };

    class EngineRenderer{
    public:
        EngineRenderer();
        ~EngineRenderer();

        void InitRenderer();
        bool Run();
        void CleanUp();

    private:
        VkInstance m_VkInstance;
        VkDebugUtilsMessengerEXT m_DebugMessenger;
        VkPhysicalDevice m_PhysicalDevice;
        VkDevice m_DeviceAbstraction;
//        RendererExternal m_
    };

}