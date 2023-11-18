#include "EngineWindow.h"
#include <iostream>

namespace engine{
    namespace {
        void WindowErrorCallback(int error, const char* description){
            std::cerr << "Window error: " <<  error << description << "\n";
        }

        void WindowCloseCallback(GLFWwindow* window){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowFocusCallback(GLFWwindow* window, int focused){
            // TODO: have fun with when the window is focused and the alternative
            if(focused == GLFW_TRUE){
                glfwFocusWindow(window);
                glfwSetWindowTitle(window, "The One and Only Engine.");
                std::cout << "Engine window focused.\n";
            }else{
                glfwSetWindowTitle(window, "Hey! Where are you going?");
                std::cout << "Engine window losses thy attention.\n";
            }
        }

        void WindowSizeCallback(GLFWwindow* window, int width, int height){
            glfwSetWindowSize(window, width, height);
        }

        void WindowCursorPositionCallback(GLFWwindow* window, double x, double y){
//            // TODO: Keep track of cursor position as input
            glfwSetCursorPos(window, x, y);
            std::cout << "Cursor position: (" << x << "," << y << ")\n";
        }
    }

    bool EngineWindow::InitWindow(WindowProperties& windowProperties) {
        // Initialize window with properties
        mWinProperties = windowProperties;

        // GLFW initialization
        auto isInitialized = glfwInit();
        if(!isInitialized)
            return false;

        // GLFW window hints setup
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // Create GLFW window
        mGlfwWindow = glfwCreateWindow(
                mWinProperties.WindowSize.Width,
                mWinProperties.WindowSize.Height,
                mWinProperties.WindowTitle,
                mWinProperties.WindowMonitor,
                mWinProperties.WindowShare);

        if(!mGlfwWindow){
            return false;
        }

        // Set up window callback events
        glfwSetErrorCallback(WindowErrorCallback);
        glfwSetWindowCloseCallback(mGlfwWindow, WindowCloseCallback);
        glfwSetKeyCallback(mGlfwWindow, WindowKeyCallback);
        glfwSetWindowFocusCallback(mGlfwWindow, WindowFocusCallback);
        glfwSetWindowSizeCallback(mGlfwWindow, WindowSizeCallback);
        glfwSetCursorPosCallback(mGlfwWindow, WindowCursorPositionCallback);

        return true;
    }

    void EngineWindow::Run(){
        glfwPollEvents();
    }

    void EngineWindow::CleanUpWindow() {
        glfwDestroyWindow(mGlfwWindow);
        glfwTerminate();
    }

    bool EngineWindow::ShouldClose() {
        return glfwWindowShouldClose(mGlfwWindow);
    }

}