#include <iostream>
using namespace std;
class Shape {
private:
  unsigned int height;
  char symbol;
  string color;
int width;

  int **tab;

  int x;
  int y;

public:
  static int counter;  
  void print();
  
  Shape(int h, char s = '*', string c = "white");

  ~Shape();


  friend class Forest;
};