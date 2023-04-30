#include <iostream>
#include <string>
#include "Rectangle.hpp"

Rectangle::Rectangle(){
x=10;
y=10;
}

Rectangle::Rectangle(int xp, int yp){
x=xp;
y=xp;

}

int Rectangle::getX(){
        return x;
        }

int Rectangle::getY(){
        return y;
        }
 void Rectangle::setX(int i){
     if(i>0){
            x=i;
     }
 }

 void Rectangle::setY(int i){
 if(i>0){
    y=i;
 }
 }





