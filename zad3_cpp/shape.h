#pragma once
#include <iostream>
using namespace std;


class Shape {
protected:
	int height;
	int width;
	char symbol;
	string color;
	string colorname;
	int** tab;
	int x, y;
public:
	virtual void Fill() = 0;
	void Alloc();
	void Print();
	Shape* SetXY(int y, int x);
	Shape(int h, char s, string c);
	~Shape();
	static int counter;
	friend class Forest;
};
