#include "VulkanBase.hpp"

namespace engine{
    VkResult VulkanBase::createInstance(bool enableValidation) {
        this->mSettings.validation = enableValidation;

        VkApplicationInfo applicationInfo = {};
        applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        applicationInfo.pApplicationName = "Vulkan Base";
        applicationInfo.pEngineName = "Vulkan Engine";
        applicationInfo.apiVersion = 1;

        std::vector<const char*> instanceExtensions = { VK_KHR_SURFACE_EXTENSION_NAME };


        // Get extensions and store them
        uint32_t  extCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extCount, nullptr);

        if(extCount > 0){
            std::vector<VkExtensionProperties> extensions(extCount);
            if (vkEnumerateInstanceExtensionProperties(nullptr, &extCount, &extensions.front()) == VK_SUCCESS){
                for(auto& extension : extensions){
                    supportedInstanceExtensions.emplace_back(extension.extensionName);
                }
            }
        }

        return VK_ERROR_OUT_OF_DEVICE_MEMORY;
    }

    bool VulkanBase::initVulkan() {
        return false;
    }
}