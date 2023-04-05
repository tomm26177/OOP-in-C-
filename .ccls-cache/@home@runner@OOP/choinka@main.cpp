#include "Forest.hpp"
using namespace std;
#include <iostream>
#include <vector>

int Tree::counter=0;

int main() {
  int i, j;


  Forest forest(20, 40);
  
  forest.AddTree(4, '#', "green", 2, 2);
  forest.AddTree(4, '+', "cyan", 3, 30);
  forest.AddTree(4, '=', "pink", 10, 20);
  forest.AddTree(4, '%', "green", 1, 20);
  forest.AddTree(4, '^', "blue", 16, 10);


  
 
  forest.PrintForest();

  

}