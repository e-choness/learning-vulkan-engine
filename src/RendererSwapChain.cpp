#include "RendererSwapChain.h"

namespace engine{

    void RendererSwapChain::InitSwapChain() {
        vkb::SwapchainBuilder swapchainBuilder{
            m_RendererDevices->PhysicalDevice,
            m_RendererDevices->DeviceAbstraction,
            m_RendererDevices->Surface
        };

        vkb::Swapchain vkbSwapchain = swapchainBuilder
                .use_default_format_selection()
                .set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR)
                .build()
                .value();

        m_SwapChain = vkbSwapchain.swapchain;
        m_SwapChainImages = vkbSwapchain.get_images().value();
        m_SwapChainImageViews = vkbSwapchain.get_image_views().value();
        m_SwapChainImageFormat = vkbSwapchain.image_format;
    }

    void RendererSwapChain::CleanUpSwapChain() {
        vkDestroySwapchainKHR(m_RendererDevices->DeviceAbstraction, m_SwapChain, nullptr);
    }




}