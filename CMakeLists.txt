cmake_minimum_required(VERSION 3.20)
project(GravitySim CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

add_executable(sim src/main.cpp src/glad.c)
target_include_directories(sim PRIVATE include)
target_compile_definitions(sim PRIVATE GL_SILENCE_DEPRECATION)
target_link_libraries(sim PRIVATE glfw OpenGL::GL glm::glm)