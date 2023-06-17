//
// Created by echo_ on 2023-06-16.
//
#pragma once
#include <SDL3/SDL.h>
struct RectProperties{
    RectProperties(float x, float y, float width, float height):
            X(x), Y(y), Width(width), Height(height) {};

    float X;
    float Y;
    float Width;
    float Height;
};

struct RenderProperties{
    RenderProperties(SDL_Texture* texture, double angle, SDL_FPoint* center=nullptr, SDL_RendererFlip flip=SDL_FLIP_NONE):
            Texture(texture), Angle(angle), Center(center), Flip(flip){};

    SDL_Texture* Texture;
    double Angle;
    SDL_FPoint* Center;
    SDL_RendererFlip Flip;
};
