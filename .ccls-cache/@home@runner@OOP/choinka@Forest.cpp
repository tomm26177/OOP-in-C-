

#ifndef FOREST_H
#define FOREST_H

#include <vector>
#include "Tree.cpp"

class Forest {
private:
std::vector<Tree*> trees;
char** grid;
int width, height;

public:
Forest(int w, int h) : width(w), height(h) {
// alokacja pamięci dla siatki lasu
grid = new char*[height];
for (int i = 0; i < height; i++) {
grid[i] = new char[width];
for (int j = 0; j < width; j++) {
grid[i][j] = ' ';
}
}
}



void AddTree(Tree* t, int x, int y) {
    // dodanie drzewa do wektora
    trees.push_back(t);

    // przepisanie drzewa do siatki lasu
    for (int i = 0; i < t->getHeight(); i++) {
        for (int j = 0; j < t->getWidth(); j++) {
            if (t->getSymbol(i, j) != ' ') {
                int gridX = x + j;
                int gridY = y + i;
                if (gridX >= 0 && gridX < width && gridY >= 0 && gridY < height) {
                    grid[gridY][gridX] = '0' + trees.size(); // zapisanie numeru drzewa jako znak
                }
            }
        }
    }
}

void Draw() {
    // wyświetlenie siatki lasu
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = grid[i][j];
            if (c == ' ') {
                std::cout << ' ';
            } else {
                int treeIndex = c - '0' - 1;
                if (treeIndex >= 0 && treeIndex < trees.size()) {
                    Tree* t = trees[treeIndex];
                    std::string color = t->getColor();
                    std::string symbol = t->getSymbol();
                    if (!color.empty()) {
                        std::cout << "\033[" << color << "m";
                    }
                    std::cout << symbol;
                    if (!color.empty()) {
                        std::cout << "\033[0m";
                    }
                }
            }
        }
        std::cout << '\n';
    }
}

~Forest() {
    // zwolnienie pamięci dla siatki lasu
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    // usunięcie drzew z wektora i zwolnienie pamięci
    for (int i = 0; i < trees.size(); i++) {
        delete trees[i];
    }
    trees.clear();
}
};