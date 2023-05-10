#include "triangle.h"
#include <iostream>
using namespace std;

Triangle::Triangle(int h, char s, string c) : Shape(h, s, c) {

	width = 2 * h - 1;
	Alloc();
	Fill();
}

void Triangle::Fill() {
	int i, j;

    for (j = 0; j < height; j++) {
        for (i = height - j - 1; i < height + j; i++)
            tab[j][i] = 1;
    }
}
