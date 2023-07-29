//
// Created by echo_ on 2023-07-28.
//
#include "vk_engine.h"

#include <SDL.h>
#include <SDL_vulkan.h>
#include <vk_types.h>


void VulkanEngine::init() {
    SDL_Init(SDL_INIT_VIDEO);
    auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_VULKAN);

    _window = SDL_CreateWindow(
            "Vulkan Engine",
            _windowExtent.width,
            _windowExtent.height,
            window_flags
            );
}

void VulkanEngine::cleanup() const {
    if(_isInitialized){
        SDL_DestroyWindow(_window);
    }
}

void VulkanEngine::draw() {

}

void VulkanEngine::run() {
    SDL_Event event;
    bool bQuit = false;
    while(bQuit){
        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_EVENT_QUIT)
                bQuit = true;
        }
        draw();
    }
}
