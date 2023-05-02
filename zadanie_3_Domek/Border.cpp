#include "Border.hpp"
#include <iostream>
using namespace std;

void Border::Fill() {
    int i, j;

    for (i = 0, j = 0; i < width; i++)
        tab[j][i] = 1;

    for (j = 1; j < height - 1; j++) {
        tab[j][0] = 1;
        tab[j][width - 1] = 1;
    }

    for (i = 0, j = height - 1; i < width; i++)
        tab[j][i] = 1;

};

void Border::Alloc() {
    int i, j;

    tab = new int* [height];
    for (j = 0; j < height; j++) {
        tab[j] = new int[width];
        for (i = 0; i < width; i++)
            tab[j][i] = 0;
    }
}

void Border::Print() {
    int i, j;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if (tab[j][i]) {
                cout << color << znak;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "\033[0m" << endl;
}

Border::Border(int h, int w, char s, string c) : Rectangle(h, w, s, c) {
    cout << "Konstruktor Rectangle Border" << endl;
    Alloc();
    Fill();
}

Border::Border(int h, char s, string c) : Rectangle(h, s, c) {
    cout << "Konstruktor Square Border" << endl;
    Alloc();
    Fill();
}
