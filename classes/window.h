//
// Created by tony on 10/11/2021.
//

#ifndef INC_2DHOUSE_WINDOW_H
#define INC_2DHOUSE_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <list>
#include "renderable.h"

using namespace std;

class Window {
protected:
    static int width;
    static int height;
    GLFWwindow *window;

public:
    list<Renderable*> renderables;

    Window(const char *title, int width, int height);
    void init();
    void initOpenGL();
    void create(const char *title);
    void render();
    static void resizer(GLFWwindow* window, int width, int height);
    void registerResizer();
    void processInput(GLFWwindow *window);

};


#endif //INC_2DHOUSE_WINDOW_H
