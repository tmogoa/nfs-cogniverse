cmake_minimum_required(VERSION 3.20)
project(2dhouse)

set(CMAKE_CXX_STANDARD 14)

#add glad.c to executables
add_executable(2dhouse main.cpp glad.c classes/shader.cpp classes/shader.h classes/window.cpp classes/window.h classes/renderable.h renderables/triangle.h)

find_package(OpenGL REQUIRED)
#include glfw3
find_package(glfw3 3.3 REQUIRED)

#include directories is not needed for modern cmake
#include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw)
