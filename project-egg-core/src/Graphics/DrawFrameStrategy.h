//
// Created by echo_ on 2023-06-15.
//
#pragma once
#include <string>
#include <SDL.h>
#include <Animation/Animation.h>
class DrawFrameStrategy {
public:
    virtual ~DrawFrameStrategy() {};
    virtual void DrawTexture(Animation const& animation) const = 0;
};


