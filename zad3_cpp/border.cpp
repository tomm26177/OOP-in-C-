#include "border.h"
#include <iostream>
using namespace std;

Border::Border(int h, int w, char s, string c, int m) : Rectangle(h, w, s, c) {

    marg = m;
    Cut();
}
Border::Border(Rectangle p, int m) : Rectangle(p) {

    marg = m;
    Cut();
}
void Border::Cut() {
    int i, j;
    for (j = marg; j < height - marg; j++)
        for (i = marg; i < width - marg; i++)
            tab[j][i] = -1;
}
