<!-- Headings -->
# Engine Game Genesis

A self-taught project learning about game engine architecture and functionality.

## Programming Language

### [C++20](https://en.cppreference.com/)

It provides a powerful combination of performance, modern language features, an enhanced Standard Library, compatibility, a thriving ecosystem, and portability. These factors make it an excellent choice for game engine development, empowering developers to create high-performance, feature-rich, and cross-platform experiences.

## External Libraries

### [SDL (Simple DirectMedia Layer)](https://github.com/libsdl-org/SDL)

SDL is known for its simplicity, ease of use, and versatility, making it a popular choice among developers, particularly for 2D game development and multimedia applications. It has a large and active community, extensive documentation, and numerous tutorials and examples, making it easier for developers to get started and learn how to use SDL effectively.

This is project SDL is used for rendering game objects and background, as well as handling game events and inputs.

### [tinyxml2](https://github.com/leethomason/tinyxml2)

Tinyxml2 offers a lightweight and straightforward solution for XML parsing and manipulation in C++ applications. Its simplicity, efficiency, and cross-platform compatibility make it a popular choice for developers seeking a minimalistic XML library with a focus on ease of use and performance.

In this project it is used for parsing 2D tilemaps created by tilesets.

(More to come)

## Build Tool

### [CMake](https://cmake.org/download/)

CMake simplifies the build process by providing a platform-independent configuration and generation system. Its flexibility, integration with different build systems, and support for dependency management make it a popular choice for managing complex software projects across multiple platforms and environments.

For this porject CMake will provide a more flexible building system and compilation options.

## Implemented Modules

* [x] Core game engine loop;
* [x] Renderer for static background and game object;
* [x] Basic input functionality;
* [x] Basic physics component;
* [x] Basic event handling.

## On-going Plan

* [ ] Add new CMake configurations for a better build system;
* [ ] Restructure source modules into libraries.
