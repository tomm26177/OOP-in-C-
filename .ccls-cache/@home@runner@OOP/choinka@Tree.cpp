#include <iostream>
#include <string>
using namespace std;

class Tree {

    friend class Forest;
    //friend ma wiekszy dostep niz klasy dziedziczone

private:
    int height;
    int width;
    string color;
    string symbol;
   int x;
    int y;

public:
    Tree(int ThisHeight, int ThisWidth, string ThisColor, string ThisSymbol) {
        height = ThisHeight;
        width = ThisWidth;
        color = ThisColor;
        symbol = ThisSymbol;
        draw();
    }

public:
    void draw() {

        // alokacja pamięci na trójkąt
        char** tree = new char*[height];
        for (int i = 0; i < height; i++) {
            tree[i] = new char[2 * width];
            // wypełnienie każdego wiersza spacjami
            for (int j = 0; j < 2 * width; j++) {
                tree[i][j] = ' ';
            }
        }

        // rysowanie choinki
        int k = 0;
        for (int i = 0; i < height; i++) {
            for (int j = width - i; j <= width + i; j++) {
                tree[i][j] = symbol[0];
            }
            k++;
        }

        // rysowanie pnia
        for (int i = 0; i < height / 4; i++) {
            for (int j = width - width / 4; j <= width + width / 4; j++) {
                tree[height - i - 1][j] = symbol[0];
            }
        }

        // zmiana koloru choinki
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < 2 * width; j++) {
                if (tree[i][j] == symbol[0]) {
                    cout << "\033[" << color << "m" << tree[i][j] << "\033[0m";
                }
                else {
                    cout << tree[i][j];
                }
            }
            cout << endl;
        }

        // zwolnienie pamięci
        for (int i = 0; i < height; i++) {
            delete[] tree[i];
        }
        delete[] tree;
    }
public:
    int getHeight() const {
        return height;
    }
    void setHeight(int newHeight) {
        height = newHeight;
    }

    int getWidth() const {
        return width;
    }
    void setWidth(int newWidth) {
        width = newWidth;
    }

    string getColor() const {
        return color;
    }
    void setColor(string newColor) {
        color = newColor;
    }

    string getSymbol() const {
        return symbol;
    }
    void setSymbol(string newSymbol) {
        symbol = newSymbol;
    }
   int getX(){
    return x ;
   }
    int getY(){
    return y ;
   }


 
};


