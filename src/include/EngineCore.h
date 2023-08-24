//
// Created by echo_ on 2023-07-27.
//
#pragma once
#include "EngineWindow.h"
#include <volk.h>

namespace engine{
    class EngineCore {
    public:
        EngineCore();
        ~EngineCore() = default;
        void Init();
        void Run();
        void CleanUp();
    private:
        void InitVulkan();
    private:
        EngineWindow* m_Window;
        VkInstance m_VkInstance;
        VkDebugUtilsMessengerEXT m_DebugMessenger;
        VkPhysicalDevice m_ChosenGPU;
        VkDevice m_DeviceAbstraction;
        VkSurfaceKHR m_Surface;

        bool m_IsRunning;
    };
}
