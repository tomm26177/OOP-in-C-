#include <iostream>
#include <vector>

using namespace std;

#include "forest.h"

int Shape::counter = 0;

int main()
{
	Forest forestt = Forest(15, 60);
    Trapeze* roof = new Trapeze(3, '*', "red");
	Rectangle* wall = new Rectangle(6, 14, '*', "yellow");
	Rectangle* door = new Rectangle(4, 3, '*', "cyan");
	Rectangle* trunk = new Rectangle(3, 3, '*', "red");
	Border* window = new Border(3, 6, '*', "yellow", 1);
	Triangle* treee = new Triangle(6, '*', "green");


	roof->SetXY(2, 3);
	forestt += roof;
	wall->SetXY(5, 4);
	forestt += wall;
	door->SetXY(6, 5);
	forestt += door;
	window->SetXY(6, 11);
	forestt += window;

	forestt.AddShape(treee, 3, 25);
	forestt.AddShape(trunk, 8, 29);


	forestt.PrintForest();

}
