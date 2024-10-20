#include <window.hpp>
#include <log.hpp>

Window::Window(const std::string title, const uint32_t width, const uint32_t height) : m_data({ std::move(title), width, height }) {
    if (!glfwInit()) {
        LOG_CRITICAL("GLFW Init");
        exit(1);
    }

    m_Window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), NULL, NULL);
    if (!m_Window) {
        LOG_CRITICAL("GLFW Create window");
        exit(1);
    }

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        LOG_CRITICAL("GLAD Load");
        exit(1);
    }

    glfwSetWindowUserPointer(m_Window, &m_data);
}

Window::~Window() {
    LOG_INFO("Terminate GLFW");
    glfwTerminate();
}

bool Window::is_close() {
    return glfwWindowShouldClose(m_Window);
}

void Window::on_update() {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}