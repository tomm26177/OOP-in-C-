#include "Shape.hpp"
using namespace std;

void Shape::print() {
  
  for (int i = 0; i < height; i++) {
    for (int j = height - i; j >= 0; j--) {
      cout << " ";
    }
    for (int j = 0; j < 2 * i + 1; j++) {
      cout << color << "\033[;32m*\033[0m";
    }
    cout << endl;
  }

}



Shape::Shape(int h, char s, string c) {
  height = h;
  symbol = s;

  if (c == "green")
    color = "\033[1;32m";
  if (c == "yellow")
    color = "\033[1;33m";
  if (c == "red")
    color = "\033[1;31m"; 
  if (c == "blue")
    color = "\033[1;34m"; 
  if (c == "purple")
    color = "\033[1;35m"; 
  if (c == "cyan")
    color = "\033[1;36m"; 
  
  tab = new int *[height];
  
  for (int j = 0; j < height; j++) {
    tab[j] = new int[2 * height - 1];
    for (int i = 0; i < 2 * height - 1; i++) {
      tab[j][i] = 0;
    }
  }

  for (int j = 0; j < height; j++)
    for (int i = height - j - 1; i < height + j; i++)
      tab[j][i] = 1;
}



Shape::~Shape() {
  for (int j = 0; j < height; j++) {
    delete tab[j];
  }
  delete tab;
  counter--;
  cout << endl << "delete tree" << endl;
}
