#include <iostream>
#include <SDL.h>

class Game {
public:
    Game(const char* title, int width, int height) : title(title), width(width), height(height) {}

    bool init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! Error: " << SDL_GetError() << std::endl;
            return false;
        }

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            std::cerr << "Renderer could not be created! Error: " << SDL_GetError() << std::endl;
            return false;
        }

        return true;
    }

    void run() {
        bool running = true;

        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Game logic and rendering code here

            SDL_RenderPresent(renderer);
            SDL_Delay(16);
        }
    }

    void cleanup() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

private:
    const char* title;
    int width;
    int height;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

int main(int argc, char* argv[]) {
    Game game("Minimalist Game Engine Example", 640, 480);
    if (game.init()) {
        game.run();
    }
    game.cleanup();

    return 0;
}