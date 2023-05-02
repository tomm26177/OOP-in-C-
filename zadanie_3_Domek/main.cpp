#include <iostream>
#include <string>
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Border.hpp"
#include "Forest.hpp"
#include "RightTriangle.hpp"
#include "Triangle.hpp"



int Tree::counter = 0;
int Shape::counter = 0;

int main() {

    Triangle t(3, '+', "blue");
     Border b(3, 9, '-', "white");
    Rectangle r(7, 9, '|', "green");

    t.Print();
    r.Print();
    b.Print();


    return 0;
}

