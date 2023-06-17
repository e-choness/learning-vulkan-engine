//
// Created by echo_ on 2023-06-16.
//
#pragma once
#include <string>

struct TextureProperties{
    TextureProperties(const std::string& id, const std::string& filename):
    TextureId(id), FileName(filename){};
    const std::string& TextureId;
    const std::string& FileName;
};
