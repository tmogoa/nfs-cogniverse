#include "classes/window.h"
#include "classes/shader.h"
#include "renderables/triangle.h"
#include "renderables/rectangle.h"

int Window::width;
int Window::height;

int main() {
    Window window("test", 800, 600, false);

    // renderables
    Triangle triangle;
    Rectangle rect;

    // packing renderables
    window.renderables.push_back(&rect);
    window.renderables.push_back(&triangle);

    window.initRenderables();

    // et viola!
    window.render();
}
