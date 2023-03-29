#include <vector>
#include "Tree.cpp"
#include <cstring>

class Forest {
private:
    std::vector<Tree*> trees;
    char** forestMatrix;
    int forestWidth, forestHeight;

public:
    Forest(int width, int height);
    ~Forest();

    void AddTree(Tree* t, int x, int y);
    void PrintForest();
};




Forest::Forest(int width, int height) {
    forestWidth = width;
    forestHeight = height;

    // allocate memory for the forest matrix
    forestMatrix = new char*[forestHeight];
    for (int i = 0; i < forestHeight; i++) {
        forestMatrix[i] = new char[forestWidth];
        std::memset(forestMatrix[i], ' ', forestWidth * sizeof(char));
    }
}

Forest::~Forest() {
    // free the memory for the forest matrix
    for (int i = 0; i < forestHeight; i++) {
        delete[] forestMatrix[i];
    }
    delete[] forestMatrix;

    // delete all the trees in the vector
    for (auto t : trees) {
        delete t;
    }
    trees.clear();
}

void Forest::AddTree(Tree* t, int x, int y) {
    // add the tree to the vector
    trees.push_back(t);

    // update the forest matrix with the tree symbol and color
    for (int i = 0; i < t->getHeight(); i++) {
        for (int j = 0; j < t->getWidth(); j++) {
            int posX = x + j;
            int posY = y + i;
            if (posX >= 0 && posX < forestWidth && posY >= 0 && posY < forestHeight) {
                forestMatrix[posY][posX] = t->getSymbol()[0];
            }
        }
    }
}

void Forest::PrintForest() {
    // print the forest matrix with the trees' symbols and colors
    for (int i = 0; i < forestHeight; i++) {
        for (int j = 0; j < forestWidth; j++) {
            bool printed = false;
            for (auto t : trees) {
                int posX = j - t->getX();
                int posY = i - t->getY();
                if (posX >= 0 && posX < t->getWidth() && posY >= 0 && posY < t->getHeight()) {
                    std::cout << "\033[" << t->getColor() << "m" << t->getSymbol()[0] << "\033[0m";
                    printed = true;
                    break;
                }
            }
            if (!printed) {
                std::cout << forestMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }
}


