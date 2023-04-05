#include "Tree.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Forest {

int x, y;
public:
  int H;
  int W;
  int **tab;

  vector<Tree *> trees;

  void AddTree(int h, char s, string c, int x, int y);
  void generateRandomTrees(int w, int h,int numberOfTree);
  void PrintForest();

  Forest(int h, int w);

  ~Forest();
};