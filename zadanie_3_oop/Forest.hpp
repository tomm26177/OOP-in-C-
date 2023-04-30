#include <iostream>
#include <vector>
#include "Shape.hpp"
using namespace std;
class Forest {

    private:
    int W;
    int H;

    int** tab;
    int x, y;


  vector<Shape *> shapes;

  void AddRectangle(int h, int w, char s, string c, int y, int x);
  void AddBorder(int h, int w, char s, string c, int y, int x);
  void AddTriangle(int h, int w, char s, string c, int y, int x);

  Forest(int h, int w);
  Forest();
  ~Forest();
};
