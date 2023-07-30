//
// Created by echo_ on 2023-07-28.
//
#include "vk_engine.h"
#include "EngineTypes.h"
#include "vk_init.h"

#include <SDL.h>
#include <SDL_vulkan.h>
#include <VkBootstrap.h>
#include <iostream>

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

void VulkanEngine::init() {
    SDL_Init(SDL_INIT_VIDEO);
    auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    _window = SDL_CreateWindow(
            "Vulkan Engine",
            _windowExtent.width,
            _windowExtent.height,
            window_flags
            );

    init_vulkan();

    init_swapchain();

    _isInitialized = true;
}

void VulkanEngine::cleanup() const {
    if(_isInitialized){
        vkDestroySwapchainKHR(_device, _swapchain, nullptr);

        for(int i=0; i<_swapchainImageViews.size(); i++){
            vkDestroyImageView(_device, _swapchainImageViews[i], nullptr);
        }

        vkDestroyDevice(_device, nullptr);
        vkDestroySurfaceKHR(_instance, _surface, nullptr);
        vkb::destroy_debug_utils_messenger(_instance, _debug_messager);
        vkDestroyInstance(_instance, nullptr);
        SDL_DestroyWindow(_window);
    }
}

void VulkanEngine::draw() {

}

void VulkanEngine::run() {
    SDL_Event event;
    bool shouldQuit = false;
    while(!shouldQuit){
        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_EVENT_QUIT )
                shouldQuit = true;
        }
        draw();
    }
}

void VulkanEngine::init_vulkan() {
    vkb::InstanceBuilder builder;

    auto inst_rec = builder.set_app_name("Example Vulkan Application")
            .request_validation_layers(true)
            .require_api_version(1,1,0)
            .use_default_debug_messenger()
            .build();

    vkb::Instance vkb_inst = inst_rec.value();

    _instance = vkb_inst.instance;

    _debug_messager = vkb_inst.debug_messenger;

    // Device
    SDL_Vulkan_CreateSurface(_window, _instance, &_surface);

    vkb::PhysicalDeviceSelector selector{ vkb_inst };

    vkb::PhysicalDevice physicalDevice = selector
            .set_minimum_version(1,1)
            .set_surface(_surface)
            .select()
            .value();

    vkb::DeviceBuilder deviceBuilder{ physicalDevice};

    vkb::Device vkbDevice = deviceBuilder.build().value();

    _device = vkbDevice.device;
    _chosenGPU = physicalDevice.physical_device;

}

void VulkanEngine::init_swapchain() {
    vkb::SwapchainBuilder swapchainBuilder {_chosenGPU, _device, _surface};

    vkb::Swapchain vkbSwapchain = swapchainBuilder
            .use_default_format_selection()
            .set_desired_present_mode(VK_PRESENT_MODE_FIFO_KHR)
            .set_desired_extent(_windowExtent.width, _windowExtent.height)
            .build()
            .value();

    _swapchain = vkbSwapchain.swapchain;
    _swapchainImages = vkbSwapchain.get_images().value();
    _swapchainImageViews = vkbSwapchain.get_image_views().value();

    _swapchainImageFormat = vkbSwapchain.image_format;
}
