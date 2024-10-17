#pragma once

#include <string>
#include <stdint.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gui.hpp>
#include <memory>

class Window {
    public:
        Window(const std::string title, const uint width, const uint height);
        ~Window();

        bool is_close();
        uint get_width() const { return m_data.width; }
        uint get_height() const { return m_data.height; }
        void on_update();

        std::shared_ptr<Gui> gui;

    private:
        GLFWwindow* m_Window;

        struct WindowData {
            std::string title;
            uint width;
            uint height;
            //EventCallbackFn eventCallbackFn;
        };

        WindowData m_data;
};