#include <iostream>
using namespace std;
class Tree {
private:
  unsigned int height;
  char symbol;
  string color;

  int **tab;

  int x;
  int y;

public:
  static int counter;  
  void printTree();
  
  Tree(int h, char s = '*', string c = "white");

  ~Tree();


  friend class Forest;
};