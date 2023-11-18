#pragma once

#include <volk.h>
#include <VkBootstrap.h>
#include <vector>
#include "EngineDevices.h"

namespace engine{
    class RendererSwapChain{
        public:
            void InitSwapChain();
            void CleanUpSwapChain();
            void SetRenderDevices(RendererDevices* rendererDevices) {m_RendererDevices = rendererDevices;}
        private:
            VkSwapchainKHR m_SwapChain;
            VkFormat m_SwapChainImageFormat;
            std::vector<VkImage> m_SwapChainImages;
            std::vector<VkImageView> m_SwapChainImageViews;
            RendererDevices* m_RendererDevices;
    };
}