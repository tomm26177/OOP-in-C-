#include <iostream>
using namespace std;
#include "shape.h"

class Triangle : public Shape {
public:
    using Shape::Shape;

    virtual void Fill();

    Triangle(int h, char s, string c);

};