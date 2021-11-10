//
// Created by tony on 10/11/2021.
//

#ifndef INC_2DHOUSE_TRIANGLE_H
#define INC_2DHOUSE_TRIANGLE_H

#include <iostream>
#include "../classes/renderable.h"

class Triangle: public Renderable{
public:
    void render();
};

void Triangle::render(){
    std::cout << "rendering" << endl;
}
#endif //INC_2DHOUSE_TRIANGLE_H
