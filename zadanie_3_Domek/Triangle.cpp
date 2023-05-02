#include "Triangle.hpp"
#include <iostream>
using namespace std;

void Triangle::Fill() {
    int i, j;

    for (j = 0; j < height; j++) {
        for (i = height - j - 1; i < height + j; i++)
            tab[j][i] = 1;
    }

};

void Triangle::Alloc() {
    int i, j;

    tab = new int* [height];
    for (j = 0; j < height; j++) {
        tab[j] = new int[2 * height - 1];
        for (i = 0; i < 2 * height - 1; i++)
            tab[j][i] = 0;
    }
}

void Triangle::Print() {
    int i, j;

    for (j = 0; j < height; j++) {
        for (i = 0; i < 2 * height - 1; i++) {
            if (tab[j][i]) {
                cout << color << znak;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

Triangle::Triangle(int h, char s, string c) : Shape(h, s, c) {
    cout << "Konstruktor Triangle" << endl;
    width = h;
    Alloc();
    Fill();
};
