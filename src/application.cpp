#include <application.hpp>

Application::Application(const std::string title, const uint width, const uint height) : window(std::make_shared<Window>(title, width, height))  {}
Application::Application(const std::string title) : window(std::make_shared<Window>(title, 640, 480))  {}


