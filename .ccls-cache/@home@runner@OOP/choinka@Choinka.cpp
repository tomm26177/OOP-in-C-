#include <iostream>>
#include <stdlib.h>
 

class Choinka{



private:
    int height;
    int weight;
    char symbol;



public:
Choinka(){
  draw();
}

public:
void draw(){
  
  int amoutOfSpaces = 0;
  int amoutOfStars = 0;
  

  for(int i=1; i<height*2;i=i+2){

    amoutOfStars=i;
    amoutOfSpaces=height*2-i;
drawSegment( amoutOfStars,  amoutOfSpaces);
    
  }
}

public:
void drawSegment(int amoutOfStars, int amoutOfSpaces){
   for(int i=0;i<amoutOfSpaces/2;i++){
    std::cout<<" ";
  }

  
  for(int i=0;i<amoutOfStars;i++){
   // std::cout << "\031[1;31 red text\033[0m\n";
    std::cout << symbol;
  }


   for(int i=0;i<amoutOfSpaces/2;i++){
    std::cout<<" ";
  }
 
  std::cout<<"\n";
}


public:
int getHeight(){
  return height;
}

public:
void setHeight(int h){
   height = h;
}


public:
char getSymbol(){
  return symbol;
}

public:
void setSymbol(char s){
   symbol= s;
}


};