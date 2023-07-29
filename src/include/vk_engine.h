//
// Created by echo_ on 2023-07-28.
//
#pragma once
#include "vk_types.h"

class VulkanEngine{
public:
    bool _isInitialized{false};
    int _frameNumber {0};

    VkExtent2D _windowExtent{1600, 900};
    struct SDL_Window* _window{ nullptr };

    void init();

    void cleanup() const;

    void draw();

    void run();
};