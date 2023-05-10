#include "rectangle.h"

class Trapeze : public Rectangle{
public:
	int margin;
	Trapeze(int h, char s, string c);
	void Cut();
};

