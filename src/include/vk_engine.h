//
// Created by echo_ on 2023-07-28.
//
#pragma once
#include "vk_types.h"
#include <vector>

class VulkanEngine{
public:
    bool _isInitialized{false};
    int _frameNumber {0};

    VkExtent2D _windowExtent{1600, 900};
    struct SDL_Window* _window{ nullptr };

    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debug_messager;
    VkPhysicalDevice _chosenGPU;
    VkDevice _device;
    VkSurfaceKHR _surface;

    VkSwapchainKHR _swapchain;
    VkFormat _swapchainImageFormat;
    std::vector<VkImage> _swapchainImages;
    std::vector<VkImageView> _swapchainImageViews;

    void init();

    void cleanup() const;

    void draw();

    void run();

private:
    void init_vulkan();
    void init_swapchain();
};