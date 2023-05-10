#include "forest.h"
#include <cassert>

Forest::Forest(int h, int w) {
    H = h;
    W = w;
    tab = new int* [H];
    for (int j = 0; j < H; j++) {
        tab[j] = new int[W];
        for (int i = 0; i < W; i++) {
            tab[j][i] = 0;
        }
    }
}
Forest::~Forest() {
    for (auto t : shapes) {
        delete t;
    }
    shapes.clear();
    int j;
    for (j = 0; j < H; j++) {
        delete tab[j];
    }
    delete tab;
}
void Forest::PrintForest() {
    int i, j;
    cout << "==============================LAS===================================" << endl;
    for (j = 0; j < H; j++) {
        for (i = 0; i < W; i++) {
            int k = tab[j][i];
            assert(k >= -1 && k <= shapes.size());
            if (k) {
                cout << shapes[k - 1]->color;
                cout << shapes[k - 1]->symbol;
            }
            else
                cout << " ";
        }
        cout << "\033[0m" << endl;
    }
    cout << "====================================================================" << endl;

}
Forest& Forest::operator+=(Shape* sh) {
    this->AddShape(sh, sh->y, sh->x);
    return *this;
}
void Forest::AddShape(Shape* sh, int y, int x) {
    int i, j;
    sh->x = x;
    sh->y = y;
    shapes.push_back(sh);
    for (j = 0; j < sh->height; j++)
        for (i = 0; i < sh->width; i++) {
            if (sh->tab[j][i] == 1)
                tab[j + y][i + x] = sh->tab[j][i] * shapes.size();
            else
                tab[j + y][i + x] = 0;
        }
}
