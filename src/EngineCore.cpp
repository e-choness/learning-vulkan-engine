#include "EngineCore.h"
#include <iostream>
#include <VkBootstrap.h>

namespace engine{
    EngineCore::EngineCore() {
        auto winProperties = WindowProperties{1600, 900, "Vulkan Engine", nullptr, nullptr};
        m_Window = new EngineWindow(winProperties);
//        m_Renderer = std::make_unique<EngineRenderer>();
        m_IsRunning = false;
    }

//    EngineCore::~EngineCore() {
//
//    }

    void EngineCore::Init() {
        m_Window->InitWindow();
        if(!m_Window->IsInitialized()){
            m_IsRunning = false;
        }
        m_IsRunning = true;
        std::cout << "Engine initialized\n";
//        m_Renderer->SetWindow(m_Window);
//        m_Renderer->InitRenderer();
    }

    void EngineCore::InitVulkan() {
        vkb::InstanceBuilder builder;

        auto InstanceRect = builder.set_app_name("God Howard")
                .request_validation_layers(true)
                .require_api_version(1,1,0)
                .use_default_debug_messenger()
                .build();

        vkb::Instance VkbInstance = InstanceRect.value();

        m_VkInstance = VkbInstance.instance;
        m_DebugMessenger = VkbInstance.debug_messenger;
    }

    void EngineCore::Run() {

        while (m_IsRunning) {
            //TODO: Engine Running Logic Here
            m_Window->Run();
            m_IsRunning = !m_Window->ShouldClose();
        }
    }

    void EngineCore::CleanUp() {
        if(!m_Window){
            std::cout << "No window is initiated\n";
            return;
        }
        m_Window->CleanUpWindow();
        std::cout << "Engine cleaned up.\n";
    }
}

