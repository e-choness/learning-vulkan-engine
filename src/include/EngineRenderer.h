//
// Created by echo_ on 2023-07-28.
//
#pragma once
#include <volk.h>
#include "EngineWindow.h"
#include "EngineDevices.h"

namespace engine{
    class EngineRenderer{
    public:
        EngineRenderer();
        ~EngineRenderer();

        void InitRenderer();
        bool Run();
        void CleanUp();
        void SetWindow(EngineWindow* window) {m_Window = window;}
        RendererDevices* GetRendererDevices() {return &m_RendererDevices;}

    private:
        void InitInstance();

    private:
        VkInstance m_VkInstance;
        VkDebugUtilsMessengerEXT m_DebugMessenger;
        RendererDevices m_RendererDevices;
        EngineWindow* m_Window;
    };

}