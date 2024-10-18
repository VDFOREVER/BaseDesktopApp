#pragma once

#include <string>
#include <window.hpp>
#include <gui.hpp>
#include <memory>

class Application {
    public:
        Application(const std::string title);
        Application(const std::string title, const uint32_t width, const uint32_t height);

        template <typename Func>
        void run(Func&& f) {
            while (!window->is_close()) {
                glClear(GL_COLOR_BUFFER_BIT);

                gui->NewFrame();
                ImGui::SetNextWindowPos(ImVec2(0, 0));
                ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y));
                ImGui::Begin("root", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
                f();
                ImGui::End();
                gui->Render();
                window->on_update();
            }
        }

        std::shared_ptr<Window> get_window() const { return window; }

    private:
        std::shared_ptr<Window> window;
        std::shared_ptr<Gui> gui;
};