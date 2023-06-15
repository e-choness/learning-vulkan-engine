cmake_minimum_required(VERSION 3.25)
project(ThirdParty LANGUAGES C CXX)

#--------------------------------------------------------------------
# SDL2
#--------------------------------------------------------------------
#set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2)
#set(SDL2_FILES ${SDL2_DIR}/)
#
#file(GLOB_RECURSE SDL2_FILES ${SDL2_DIR}/include/*.h ${SDL2_DIR}/src/*.h ${SDL2_DIR}/src/*.c)
#
#add_library(SDL2 SHARED ${SDL2_FILES})
#
#target_include_directories(SDL2 PUBLIC ${SDL2_DIR}/include ${SDL2_DIR}/src/)
#
#set_target_properties(SDL2 PROPERTIES LINKER_LANGUAGE C)
#
#add_subdirectory(${SDL2_DIR})
#
#set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")
#
#include(FetchContent)

set(SDL_SHARED OFF)
set(SDL_STATIC ON)
set(SDL_TEST OFF)
add_subdirectory(SDL2)
#set(BUILD_SHARED_LIBS FALSE)
#option(SDL_SHARED FALSE)
#--------------------------------------------------------------------
# SDL2_IMAGE
#--------------------------------------------------------------------
#set(SDL2_IMAGE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image)
#set(SDL2_IMAGE_FILES ${SDL2_IMAGE_DIR}/)
#
#file(GLOB_RECURSE SDL2_IMAGE_HEADER_FILES ${SDL2_IMAGE_DIR}/include/*.h )
#file(GLOB SDL2_IMAGE_SOURCE_FILES ${SDL2_IMAGE_DIR}/*.h ${SDL2_IMAGE_DIR}/*.c)
#
#add_library(SDL2_IMAGE SHARED ${SDL2_IMAGE_HEADER_FILES} ${SDL2_IMAGE_SOURCE_FILES})
#
#target_include_directories(SDL2_IMAGE PUBLIC ${SDL2_IMAGE_DIR}/include ${SDL2_IMAGE_DIR})
#
#set_target_properties(SDL2_IMAGE PROPERTIES LINKER_LANGUAGE C)
#
#add_subdirectory(${SDL2_IMAGE_DIR})
#include(FetchContent)
#FetchContent_Declare(
#        SDL2_image
#        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
#        GIT_SHALLOW TRUE
#        GIT_PROGRESS TRUE
#        GIT_TAG main)
#
#FetchContent_MakeAvailable(SDL2_image)
##FetchContent_Populate(SDL2_image)
#
##add_subdirectory(${sdl2image_SOURCE_DIR} ${sdl2image_BINARY_DIR})
#
#include_directories(${sdl2image_SOURCE_DIR}/include)

#target_include_directories(SDL2_image PUBLIC
#        ${sdl2image_SOURCE_DIR}/include
#        ${sdl2image_SOURCE_DIR})
#set(SDL2IMAGE_INSTALL OFF)
#set(BUILD_SHARED_LIBS FALSE)

set(BUILD_SHARED_LIBS OFF)
#set(SDL_STATIC ON)
#set(SDL_TEST OFF)
add_subdirectory(SDL2_image)

##--------------------------------------------------------------------
# TINYXML2
#--------------------------------------------------------------------
#set(TINYXML2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2)
#set(TINYXML2_FILES ${TINYXML2_DIR}/)
#
#file(GLOB TINYXML2_FILES ${TINYXML2_DIR}/*.h ${TINYXML2_DIR}/*.c)
#
#add_library(TINYXML2 SHARED ${TINYXML2_FILES})
#
#target_include_directories(TINYXML2 PUBLIC ${TINYXML2_DIR})
#
#set_target_properties(TINYXML2 PROPERTIES LINKER_LANGUAGE CXX)

#add_subdirectory(${TINYXML2_DIR})
include(FetchContent)
FetchContent_Declare(
        tinyxml2
        GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
        GIT_TAG master)

FetchContent_MakeAvailable(tinyxml2)
#FetchContent_Populate(tinyxml2)
include_directories(${tinyxml2_SOURCE_DIR}/include)

#target_include_directories(tinyxml2 PUBLIC
#        ${tinyxml2_SOURCE_DIR})