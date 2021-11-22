//
// Created by tony on 10/11/2021.
//

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"

using namespace std;

Window::Window(const char *title, int width, int height, bool wrFrameMode) {
    Window::width = width;
    Window::height = height;
    Window::renderables = {};
    init();
    create(title);
    initOpenGL();
    registerResizer();

    if(wrFrameMode){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

void Window::init() {
    glfwInit();
    // setting major and minor version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //use the core profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // for Mac OS X
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void Window::initOpenGL() {
    // use glad to locate opengl functions (OS specific)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    // set opengl viewport dimens
    glViewport(0, 0, width, height);
}

void Window::create(const char *title) {
    // create the window object
    Window::window = glfwCreateWindow(800, 600, title, NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        exit(-1);
    }
    //set window as main context for current thread
    glfwMakeContextCurrent(window);
}

void Window::resizer(GLFWwindow *window, int width, int height) {
    Window::width = width;
    Window::height = height;
    glViewport(0, 0, width, height);
}

void Window::registerResizer() {
    glfwSetFramebufferSizeCallback(window, resizer);
}

void Window::processInput(GLFWwindow *window) {
    // check whether ESC key was pressed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Window::initRenderables() {
    list<Renderable*>::iterator it = renderables.begin();
    for (; it != renderables.end(); it++) {
        (*it)->init();
    }
}

void Window::render() {
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //rendering renderables here
        list<Renderable*>::iterator it = renderables.begin();
        for (; it != renderables.end(); it++) {
//            (*it)->init();
            (*it)->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    exit(0);
}
