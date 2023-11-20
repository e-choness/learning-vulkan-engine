#pragma once

#include <volk.h>
#include <vulkan/vulkan.h>
#include <chrono>

namespace engine{
    struct Settings {
        bool validation = false;
        bool fullscreen = false;
        bool vsync = false;
        bool overlay = true;
    };

    class VulkanBase{
    public:


        VkResult createInstance(bool enableValidation);
        bool initVulkan();

        VkInstance mInstance;
        Settings mSettings;
        std::vector<std::string> supportedInstanceExtensions;
    };
}
