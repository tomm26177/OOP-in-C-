#include <iostream>
#include <string>
using namespace std;
 

class Choinka{

friend class Forest;
//friend ma wiekszy dostep niz klasy dziedziczone

private:
    int height;
    int weight;
    int Color;
    char symbol;




public:
Choinka(int ThisHeight, int ThisWidth, int ThisColor, char ThisSymbol){
  height=ThisHeight; 
  weight = ThisWidth; 
  Color= ThisColor;
  symbol = ThisSymbol;
  
  
  draw();
  
}

public:
void draw(){



    int height, width;
    string color, symbol;
    cout << "Podaj wysokość choinki: ";
    cin >> height;
    cout << "Podaj szerokość choinki: ";
    cin >> width;
    cout << "Podaj kolor choinki: ";
    cin >> color;
    cout << "Podaj symbol choinki: ";
    cin >> symbol;

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


public:
void drawSegment(int amoutOfStars, int amoutOfSpaces){
   for(int i=0;i<amoutOfSpaces/2;i++){
    std::cout<<" ";
  }

  
  for(int i=0;i<amoutOfStars;i++){
    //std::cout << "\031[1;31 red text\033[0m\n";
    std::cout << symbol;
  }


   for(int i=0;i<amoutOfSpaces/2;i++){
    std::cout<<" ";
  }
 
  std::cout<<"\n";
}







public:
int getHeight(){
  return height;
}

public:
void setHeight(int h){
   height = h;
}


public:
char getSymbol(){
  return symbol;
}

public:
void setSymbol(char s){
   symbol= s;
}


};