#include<math.h>
class Circle{
public:
double radius;


public:
double calcuteSurface(){
  return M_PI* pow(radius, radius );
}

public:
double calcuteLenth(){
  return 2*M_PI*radius;
}
};

