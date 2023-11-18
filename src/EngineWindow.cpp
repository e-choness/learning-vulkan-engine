#include "EngineWindow.h"
#include <iostream>

namespace engine{
    namespace {
        // Window mode position offsets
        const int WINDOW_X_OFFSET = 100;
        const int WINDOW_Y_OFFSET = 60;

        // Window mode default height and width
        const int DEFAULT_WIDTH = 1600;
        const int DEFAULT_HEIGHT = 900;

        // Opacity settings
        const float WINDOW_SOLID = 1.0f;
        const float WINDOW_OPAQUE = 0.86f;

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
                int xPos, yPos, width, height;
                glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &xPos, &yPos, &width, &height);
                glfwSetWindowPos(window, xPos, yPos);

                glfwSetWindowSize(window, width, height);
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
                glfwSetWindowOpacity(window, WINDOW_SOLID);
                glfwSetWindowTitle(window, "The One and Only Engine.");
                std::cout << "Engine window focused.\n";
            }

            else{
                glfwSetWindowTitle(window, "Hey! Where are you going?");
                glfwSetWindowOpacity(window, WINDOW_OPAQUE);
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

    void EngineWindow::CleanUp() {
        glfwDestroyWindow(mGlfwWindow);
        glfwTerminate();
    }

    bool EngineWindow::ShouldClose() {
        return glfwWindowShouldClose(mGlfwWindow);
    }

}