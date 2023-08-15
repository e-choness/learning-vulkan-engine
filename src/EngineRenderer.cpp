//
// Created by echo_ on 2023-07-28.
//
#include "EngineRenderer.h"
#include <iostream>
#include <VkBootstrap.h>

#define VK_CHECK(x)                 \
    do                              \
    {                               \
        VkResult err = x;           \
        if (err)                    \
        {                           \
            std::cout << "Detected Vulkan error: " << err << "\n"; \
            abort();                \
        }                           \
    } while(0)                      \
}
namespace engine{
    namespace {
        //TODO: add allocator
    }
    EngineRenderer::EngineRenderer() {

    }

    EngineRenderer::~EngineRenderer() {

    }

    void EngineRenderer::InitRenderer() {
        InitInstance();

    }

    bool EngineRenderer::Run() {
        return false;
    }

    void EngineRenderer::CleanUp() {

    }

    void EngineRenderer::InitInstance() {
        vkb::InstanceBuilder instanceBuilder;

        auto instRet = instanceBuilder.set_app_name("God Howard") // All hail Todd Howard
                .request_validation_layers(true) // Enable validation layer
                .require_api_version(1,1, 0) // Choose vulkan api version 1.1.0
                .use_default_debug_messenger() // The debugger will directly output validation errors to the console
                .build();

        vkb::Instance vkbInstance = instRet.value();

        m_VkInstance = vkbInstance.instance;
        m_DebugMessenger = vkbInstance.debug_messenger;
        if(!m_Window)
        {
            std::cout<< "No window for the renderer.\n";
            return;
        }

        glfwCreateWindowSurface(m_VkInstance, m_Window->GetWindowInstance(), nullptr,&m_RendererDevices.Surface);

        vkb::PhysicalDeviceSelector selector{ vkbInstance };
        vkb::PhysicalDevice physicalDevice = selector
                .set_minimum_version(1,1)
                .set_surface(m_RendererDevices.Surface)
                .select()
                .value();

        vkb::DeviceBuilder deviceBuilder{ physicalDevice};
        vkb::Device vkDevice = deviceBuilder.build().value();

        m_RendererDevices.DeviceAbstraction = vkDevice.device;
        m_RendererDevices.PhysicalDevice = physicalDevice.physical_device;

    }



}
