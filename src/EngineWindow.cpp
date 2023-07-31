//
// Created by echo_ on 2023-07-29.
//
#include "EngineWindow.h"
#include <iostream>
namespace engine{
    namespace {
        void WindowErrorCallback(int error, const char* description){
            std::cout << stderr << "Window error: " << description << "\n";
        }

        void WindowCloseCallback(GLFWwindow* window){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
            if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        void WindowFocusCallback(GLFWwindow* window, int focused){
            // TODO: set window focus state
            // app.SetFocused();
        }

        void WindowSizeCallback(GLFWwindow* window, int width, int height){
            glfwSetWindowSize(window, width, height);
        }

        void WindowTitleCallback(GLFWwindow* window, const char* title){
            glfwSetWindowTitle(window, title);
        }

        void WindowCursorPositionCallback(GLFWwindow* window, double x, double y){
//            // TODO: Keep track of cursor position as input
//            glfwSetCursorPos(window, x, y);
//            std::cout << "Cursor position: (" << x << "," << y << ")\n";
        }
    }
    EngineWindow::EngineWindow(WindowProperties& windowProperties){
        SetProperties(windowProperties);
    }

//    EngineWindow::~EngineWindow() {
//
//    }

    void EngineWindow::SetProperties(WindowProperties& windowProperties){
        m_WinProperties = windowProperties;
    }

    bool EngineWindow::InitWindow() {
        m_IsInitialized = glfwInit();
        if(!m_IsInitialized)
            return -1;

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_WindowInstance = glfwCreateWindow(
                static_cast<int>(m_WinProperties.Size.Width),
                static_cast<int>(m_WinProperties.Size.Height),
                m_WinProperties.WindowTitle,
                m_WinProperties.WindowMonitor,
                m_WinProperties.WindowShare);
        if(!m_WindowInstance){
            m_IsInitialized = false;
            return m_IsInitialized;
        }
        glfwSetErrorCallback(WindowErrorCallback);
        glfwSetWindowCloseCallback(m_WindowInstance, WindowCloseCallback);
        glfwSetKeyCallback(m_WindowInstance, WindowKeyCallback);
        glfwSetWindowFocusCallback(m_WindowInstance, WindowFocusCallback);
        glfwSetWindowSizeCallback(m_WindowInstance, WindowSizeCallback);
        glfwSetCursorPosCallback(m_WindowInstance, WindowCursorPositionCallback);

        return m_IsInitialized;
    }

    void EngineWindow::Run(){
        glfwPollEvents();
    }

    void EngineWindow::CleanUpWindow() {
        glfwDestroyWindow(m_WindowInstance);
        glfwTerminate();
    }

    bool EngineWindow::ShouldClose() {
        return glfwWindowShouldClose(m_WindowInstance);
    }

    double EngineWindow::GetTime() {
        return glfwGetTime();
    }

    bool EngineWindow::IsInitialized() {
        return m_IsInitialized;
    }

    void EngineWindow::SetTitle(const char* title){
        glfwSetWindowTitle(m_WindowInstance, title);
    }
}