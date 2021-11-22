//
// Created by tony on 10/11/2021.
//

#ifndef INC_2DHOUSE_TRIANGLE_H
#define INC_2DHOUSE_TRIANGLE_H

#include <iostream>
#include "../classes/renderable.h"

class Triangle: public Renderable{
public:
    unsigned int VAO;
    Shader *tShader;
    void init();
    void render();
};

void Triangle::init() {
    //compile and link shaders
    tShader = new Shader("shaders/vertex.vs", "shaders/fshader.fs");

    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.5f, 0.0f
    };

    // vertex array object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // linking vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // unbind vertex array buffer
    glBindVertexArray(0);

}

void Triangle::render(){
    tShader->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // unbind vertex array buffer
    glBindVertexArray(0);
}
#endif //INC_2DHOUSE_TRIANGLE_H
