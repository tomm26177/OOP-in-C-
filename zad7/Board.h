#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum class CellState
{
    Empty,
    Ship,
    Hit,
    Miss
};

class Board
{
public:
    Board(int size);
    void placeShip(int x, int y, int length, bool vertical);
    bool canPlaceShip(int x, int y, int length, bool vertical) const;
    bool isCellEmpty(int x, int y) const;
    void markCellAsShip(int x, int y);
    void markCellAsHit(int x, int y);
    void markCellAsMiss(int x, int y);
    bool isAllShipsSunk() const;
    friend std::ostream &operator<<(std::ostream &os, const Board &board);

public:
    std::vector<std::vector<CellState>> grid;
    int boardSize;
};

#endif
