#include <iostream>

using namespace std;

#include "Shape.hpp"

void Shape::print() {
  int i, j;

  for (j = 0; j < height; j++) {
    for (i = 0; i < width; i++) {
      if (tab[j][i]) {
        cout << color << znak;
      } else {
        cout << "";
      }
    }
    cout << endl;
  }
  cout << "\033[0m" << endl;
}

Shape::Shape(int h, char z, string c) {
  int j, i;
  height = h;
  znak = z;
  color = c;

  if (c == "green")
    color = "\033[1;32m";

  if (c == "red")
    color = "\033[1;31m";

  if (c == "blue")
    color = "\033[1;34m";

  counter++;

  cout<< "Konstruktor Shape"<< endl;
}

// to bedzie robila funckja Alloc
void Shape::Alloc() {
  int i, j;
  tab = new int *[height];
  for (j = 0; j < height; j++) {
    tab[j] = new int[width];
    for (i = 0; i < width; i++)
      tab[j][i] = 0;
  }
}

/*for (j = 0; j < height; j++) {
  for (i = height - j - 1; i < height + j; i++) {
    tab[j][i] = 1;
  }
}*/ //to bedzie robila funkcja Fill

Shape::~Shape() {
  int j;
  for (j = 0; j < height; j++) {
    delete tab[j];
  }
  delete tab;
  counter--;
  cout << endl << "Kasuje Shape: zostalo " << counter << endl;
}
