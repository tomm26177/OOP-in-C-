//
// Created by 48510 on 08.06.2023.
//
#include "Board.cpp"

class Cell {
private:
    char state;
public:
    Cell() : state(Board::EMPTY) {}
    char getState() const { return state; }
    void setState(char s) { state = s; }

};