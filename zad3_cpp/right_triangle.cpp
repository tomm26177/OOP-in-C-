#include "right_triangle.h"
#include <iostream>
using namespace std;

RTriangle::RTriangle(int h, char s, string c) : Shape(h, s, c) {

    width = (2*h)-1;
    Alloc();
    Fill();
}

void RTriangle::Fill() {
    int i, j;

    for (j = 0; j < height; j++)
        for (i = 0; i <= j; i++)
            tab[j][i] = 1;
}
