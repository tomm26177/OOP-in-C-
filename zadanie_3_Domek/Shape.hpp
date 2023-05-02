#include <iostream>
using namespace std;
#pragma once

class Shape {
protected:
    int height;
    int width;
    char znak;
    string color;

    int** tab;

    int x, y;
   // static int counter;


public:
    Shape(int h, char z, string c);
    ~Shape();

    virtual void Alloc() = 0;
    virtual void Fill() = 0;
    virtual void Print() = 0;

    friend class Forest;
};
