#pragma once

#include <string>
#include <window.hpp>
#include <memory>

class Application {
    public:
        Application(const std::string title);
        Application(const std::string title, const uint width, const uint height);

        template <typename Func>
        void run(Func&& f) {
            while (!window->is_close()) {
                glClear(GL_COLOR_BUFFER_BIT);

                window->gui->NewFrame();
                ImGui::SetNextWindowPos(ImVec2(0, 0));
                ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y));
                ImGui::Begin("root", &is_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoSavedSettings);
                f();
                ImGui::End();
                window->gui->Render();
                window->on_update();
            }
        }

    private:
        std::shared_ptr<Window> window;
        bool is_open = true;
};