#pragma once

#include <string>
#include <stdint.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class Window {
    public:
        Window(const std::string title, const uint32_t width, const uint32_t height);
        ~Window();

        bool is_close();
        uint32_t get_width() const { return m_data.width; }
        uint32_t get_height() const { return m_data.height; }
        GLFWwindow* get_native_window() const { return m_Window; }
        void on_update();

    private:
        GLFWwindow* m_Window;

        struct WindowData {
            std::string title;
            uint32_t width;
            uint32_t height;
        };

        WindowData m_data;
};