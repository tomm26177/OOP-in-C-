#include "Forest.hpp"
using namespace std;
void Forest::AddTree(int h, char s, string c, int y, int x) {
  Tree *tree = new Tree(h, s, c);
  tree->x = x;
  tree->y = y;

  int j, i;
  trees.push_back(tree);
  for (j = 0; j < tree->height; j++) {
    for (i = 0; i < 2 * tree->height - 1; i++)
      tab[j + y][i + x] = tree->tab[j][i] * trees.size();
  }
}

Forest::Forest(int h, int w) {
  H = h;
  W = w;

  tab = new int *[H];
  for (int i = 0; i < H; i++) {
    tab[i] = new int[W];
  }
}

Forest::~Forest() {
  for (auto t : trees) {
    delete t;
  }
  for (int j = 0; j < H; j++) {
    delete tab[j];
  }
  delete tab;
  trees.clear();
}
void Forest::PrintForest() {
  int i, j;
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      int k = tab[j][i];
      if (k) {
        cout << trees[k - 1]->color;
        cout << trees[k - 1]->symbol;
      } else
        cout << " ";
    }
    cout << endl;
  }
  
}