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
                glfwFocusWindow(window);

                std::cout << "Engine goes full screen mode.\n";
            }

            // Press A to maximize window mode
            if(key == GLFW_KEY_A && action == GLFW_PRESS){
                glfwMaximizeWindow(window);
                glfwFocusWindow(window);
                std::cout << "Engine goes maximized window mode.\n";
            }

            // Press W back to window mode
            if(key == GLFW_KEY_W && action == GLFW_PRESS){
                // A bug when the first time return to window mode, it looses focus and stays at maximized window
                // Set focus window first would fix maximizing mode, but still loosing focus when returning to window mode
                glfwFocusWindow(window);

                glfwSetWindowPos(window,WINDOW_X_OFFSET, WINDOW_Y_OFFSET);
                glfwSetWindowSize(window, DEFAULT_WIDTH, DEFAULT_HEIGHT);

                std::cout << "Engine is back to window mode.\n";
            }

            // Press M to minimize the window
            if(key == GLFW_KEY_M && action == GLFW_PRESS){
                glfwIconifyWindow(window);
            }
        }

        void WindowFocusCallback(GLFWwindow* window, int focused){
            // TODO: have fun with when the window is focused and the alternative
            if(focused == GLFW_TRUE){

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
            // TODO: show cursor position when left mouse is clicked
            // Left mouse click to show cursor position
            // Dragging mouse click will update the position in the next update?
            auto key = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
            if(key == GLFW_PRESS){
                std::cout << "At engine runtime " << glfwGetTime() << "s, Cursor position: (" << x << "," << y << ")\n";
            }
        }



        void WindowIconifyCallback(GLFWwindow* window, int iconified){
            if(iconified == GLFW_TRUE){
                glfwSetWindowTitle(window, "I'm here, sitting in the corner.");
                std::cout << "Dear engine is in the little corner.\n";
            }else{
                glfwSetWindowTitle(window, "I'm back, baby!");
                std::cout << "Engine is BACK!\n";
            }
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

        SetupGlfwCallbacks();

        return true;
    }

    void EngineWindow::SetupGlfwCallbacks() {
        // Set up window callback events
        glfwSetErrorCallback(WindowErrorCallback);
        glfwSetWindowCloseCallback(mGlfwWindow, WindowCloseCallback);
        glfwSetKeyCallback(mGlfwWindow, WindowKeyCallback);
        glfwSetWindowFocusCallback(mGlfwWindow, WindowFocusCallback);
        glfwSetWindowSizeCallback(mGlfwWindow, WindowSizeCallback);
        glfwSetCursorPosCallback(mGlfwWindow, WindowCursorPositionCallback);
        glfwSetWindowIconifyCallback(mGlfwWindow, WindowIconifyCallback);
    }

    void EngineWindow::Run(){
        // Swap buffers should have OpenGL or OpenGL ES context, it's not setup yet.
//        glfwSwapBuffers(mGlfwWindow);

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