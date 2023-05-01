#include "shape.hpp"
#include <iostream>
using namespace std;

class Rectangle : public Shape {
public:
    void Fill();
    void Alloc();
    void Print();

    using Shape::Shape;
    Rectangle(int h, int w, char s, string c);
    Rectangle(int h, char s, string c);

};