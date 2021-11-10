#include "classes/window.h"
#include "renderables/triangle.h"

int Window::width;
int Window::height;

int main() {
    Window window("test", 800, 600);

    Triangle triangle;
    window.renderables.push_back(&triangle);
    window.render();
}
