#include "EngineWindow.h"
#include <iostream>

namespace engine{
    namespace {
        // Origin positions of the screen
        const uint16_t ORIGIN_POS_X = 0;
        const uint16_t ORIGIN_POS_Y = 0;

        // Window mode position offsets
        const uint16_t WINDOW_X_OFFSET = 100;
        const uint16_t WINDOW_Y_OFFSET = 60;

        // Window mode default height and width
        const uint16_t DEFAULT_WIDTH = 1600;
        const uint16_t DEFAULT_HEIGHT = 900;

        void WindowErrorCallback(int error, const char* description){
            std::cerr << "Window error: " <<  error << description << "\n";
        }

        void WindowCloseCallback(GLFWwindow* window){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
            // Press ESC to close window
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window, GLFW_TRUE);
            }

            // Press F to full screen mode
            if(key == GLFW_KEY_F && action == GLFW_PRESS)
            {
                auto mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
                glfwSetWindowPos(window, ORIGIN_POS_X, ORIGIN_POS_Y);
                glfwSetWindowSize(window, mode->width, mode->height);
                std::cout << "Engine goes full screen mode.\n";
            }

            // Press W back to window mode
            if(key == GLFW_KEY_W && action == GLFW_PRESS){
                glfwSetWindowPos(window,WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
                glfwSetWindowSize(window, DEFAULT_WIDTH, DEFAULT_HEIGHT);
                std::cout << "Engine is back to window mode.\n";
            }
        }

        void WindowFocusCallback(GLFWwindow* window, int focused){
            // TODO: have fun with when the window is focused and the alternative
            if(focused == GLFW_TRUE){
                glfwFocusWindow(window);
                glfwSetWindowOpacity(window, 1.0f);
                glfwSetWindowTitle(window, "The One and Only Engine.");
                std::cout << "Engine window focused.\n";
            }

            else{
                glfwSetWindowTitle(window, "Hey! Where are you going?");
                glfwSetWindowOpacity(window, 0.86f);
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