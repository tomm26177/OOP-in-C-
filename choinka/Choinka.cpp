#include <iostream>
#include <stdlib.h>
 

class Choinka{

friend class Forest;
//friend ma wiekszy dostep niz klasy dziedziczone

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

  /*
  int **myArray = new int*[rows];


for (int i = 0; i < rows; i++) {
    myArray[i] = new int[cols];
}


for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        myArray[i][j] = i * j;
    }
}
*/

  
  
  

    
  }


/*
  for (int i = 0; i < rows; i++) {
    delete[] myArray[i];
}
delete[] myArray;  */
}


public:
void drawSegment(int amoutOfStars, int amoutOfSpaces){
   for(int i=0;i<amoutOfSpaces/2;i++){
    std::cout<<" ";
  }

  
  for(int i=0;i<amoutOfStars;i++){
    //std::cout << "\031[1;31 red text\033[0m\n";
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