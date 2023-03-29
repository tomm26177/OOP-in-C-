#include <iostream>
#include <string>
using namespace std;

class Choinka{

friend class Forest;
//friend ma wiekszy dostep niz klasy dziedziczone

private:
    int height;
    int width;
    string color;
    string symbol;

public:
    Choinka(int ThisHeight, int ThisWidth, string ThisColor, string ThisSymbol){
        height = ThisHeight;
        width = ThisWidth;
        color = ThisColor;
        symbol = ThisSymbol;
    }

    void setHeight(int ThisHeight){
        height = ThisHeight;
    }

    void setWidth(int ThisWidth){
        width = ThisWidth;
    }

    void setColor(string ThisColor){
        color = ThisColor;
    }

    void setSymbol(string ThisSymbol){
        symbol = ThisSymbol;
    }

    void draw(){
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
                } else {
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

    void drawSegment(int amoutOfStars, int amoutOfSpaces){
        for(int i=0;i<amoutOfSpaces/2;i++){
            std::cout<<" ";
        }

        for(int i=0;i<amoutOfStars;i++){
            std::cout << symbol;
        }

        for(int i=0;i<amoutOfSpaces/2;i++){
            std
