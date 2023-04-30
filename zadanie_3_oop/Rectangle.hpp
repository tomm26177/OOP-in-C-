#include <iostream>
#include <string>

class Rectangle{

private:
    int x;
    int y;


public:
    Rectangle();
    ~Rectangle();
    Rectangle(int x, int y);
    int getX();

    int getY();

    void setX(int i);
    void setY(int i);


};
