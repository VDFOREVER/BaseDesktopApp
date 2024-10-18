#include <application.hpp>

Application::Application(const std::string title, const uint32_t width, const uint32_t height)
    : window(std::make_shared<Window>(title, width, height)),
      gui(std::make_shared<Gui>(window->get_native_window()))
{}

Application::Application(const std::string title)
    : window(std::make_shared<Window>(title, 640, 480)),
      gui(std::make_shared<Gui>(window->get_native_window()))
{}