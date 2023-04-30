#include <iostream>

using namespace std;

#include "shape.hpp"


Shape::Shape(int h, char z, string c) {
  int j, i;
  height = h;
  znak = z;
  color = c;

  if (c == "red")       color = "\033[1;31m";
  if (c == "yellow")    color = "\033[1;33m";
  if (c == "green")     color = "\033[1;32m";
  if (c == "blue")      color = "\033[1;34m";
  if (c == "cyan")      color = "\033[1;36m";
  if (c == "purple")    color = "\033[1;95m";

//  counter++;

  cout<< "Konstruktor Shape"<< endl;
}

Shape::~Shape() {
    int j;
    for (j = 0; j < height; j++) {
        delete tab[j];
    }
    delete tab;
  //  counter--;
  //  cout << endl << "Kasuje Shape: zostalo " << counter << endl;
}

