#include <iostream>
#include <string>
#include "Shape.hpp"

class Rectangle:public Shape{

private:
    int x;
    int y;


public:
    Rectangle();
    ~Rectangle();
    Rectangle(int x, int y);
    int getX();

    int getY();

    void setX(int i);
    void setY(int i);


};
