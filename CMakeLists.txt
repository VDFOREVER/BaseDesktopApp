cmake_minimum_required(VERSION 3.10)

project(gui)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_subdirectory(subprojects/glfw)
add_subdirectory(subprojects/glad)
target_link_libraries(${PROJECT_NAME} glad glfw)

#imgui
set(IMGUI_SOURCES
	subprojects/imgui/imgui.cpp
	subprojects/imgui/backends/imgui_impl_glfw.cpp
	subprojects/imgui/backends/imgui_impl_opengl3.cpp
	subprojects/imgui/imgui_demo.cpp
	subprojects/imgui/imgui_tables.cpp
	subprojects/imgui/imgui_widgets.cpp
	subprojects/imgui/imgui_draw.cpp
)

add_library(ImGui STATIC ${IMGUI_SOURCES})

target_include_directories(ImGui PUBLIC subprojects)
target_include_directories(ImGui PUBLIC subprojects/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(${PROJECT_NAME} ImGui)


add_subdirectory(examples)