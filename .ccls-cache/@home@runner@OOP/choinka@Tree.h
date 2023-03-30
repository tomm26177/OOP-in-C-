#ifndef TREE_H
#define TREE_H
#include <iostream>


class Tree {
public:
    Tree(int ThisHeight, int ThisWidth,std:: string ThisColor, std::string ThisSymbol);  
    void draw();  
private:
    int height;  // zmienna prywatna
};

#endif






