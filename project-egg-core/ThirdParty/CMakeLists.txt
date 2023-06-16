#--------------------------------------------------------------------
# Copyright (c) 2013 Echo Yin
#--------------------------------------------------------------------
cmake_minimum_required(VERSION 3.25)
project(ThirdParty LANGUAGES C CXX)

include(FetchContent)

#--------------------------------------------------------------------
# SDL3
#--------------------------------------------------------------------

#Set(FETCHCONTENT_QUIET FALSE)
#
#FetchContent_Declare(
#        SDL2
#        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#        GIT_TAG main
#        GIT_SHALLOW TRUE
#        GIT_PROGRESS TRUE
#)
#FetchContent_MakeAvailable(SDL2)
#include_directories(${sdl2_SOURCE_DIR}/include)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)
set(SDL_TEST OFF)
add_subdirectory(SDL2)

#--------------------------------------------------------------------
# SDL3_IMAGE
#--------------------------------------------------------------------

#FetchContent_Declare(
#        SDL2_image
#        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#        GIT_TAG main
#        GIT_SHALLOW TRUE
#        GIT_PROGRESS TRUE
#)
#FetchContent_MakeAvailable(SDL2_image)
#include_directories(${sdl2_image_SOURCE_DIR}/include)

set(BUILD_SHARED_LIBS OFF)
add_subdirectory(SDL2_image)

##--------------------------------------------------------------------
# TINYXML2
#--------------------------------------------------------------------

#FetchContent_Declare(
#        tinyxml2
#        GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
#        GIT_TAG master)
#
#FetchContent_MakeAvailable(tinyxml2)
add_subdirectory(tinyxml2)
set(BUILD_SHARED_LIBS OFF)
#include_directories(${tinyxml2_SOURCE_DIR}/include)
#target_include_directories(tinyxml2 PUBLIC
#        ${tinyxml2_SOURCE_DIR})