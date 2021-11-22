//
// Created by tony on 22/11/2021.
//

#ifndef INC_2DHOUSE_RECTANGLE_H
#define INC_2DHOUSE_RECTANGLE_H

#include "../classes/renderable.h"

class Rectangle: public Renderable{
public:
    unsigned int VAO;
    Shader *rShader;
    void init();
    void render();
};

void Rectangle::init() {
    //compile and link shaders
    rShader = new Shader("shaders/vertex.vs", "shaders/fragment.fs");

    float vertices[] = {
            0.5f, 0.5f, 0.0f, // top right
            0.5f, -0.5f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f // top left
    };
    unsigned int indices[] = { // note that we start from 0!
            0, 1, 3, // first triangle
            1, 2, 3 // second triangle
    };

    // vertex array object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element Buffer Objects
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // unbinding the vertex array buffer
    glBindVertexArray(0);

}

void Rectangle::render() {
    rShader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // unbinding the vertex array buffer
    glBindVertexArray(0);
}

#endif //INC_2DHOUSE_RECTANGLE_H
