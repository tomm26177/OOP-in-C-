//
// Created by 48510 on 08.06.2023.
//

#ifndef OOP_IN_C_BOARD_H
#define OOP_IN_C_BOARD_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "Cell.cpp"

class Board {
private:
    std::vector<std::vector<Cell>> grid;
public:
    static const int BOARD_SIZE = 10;
    static const char EMPTY = '.';
    static const char HIT = 'X';
    static const char MISS = 'O';
    Board() : grid(BOARD_SIZE, std::vector<Cell>(BOARD_SIZE)) {}

    // Metoda zwracająca stan komórki na planszy
    char getCellState(int row, int col) const {
        return grid[row][col].getState();
    }

    // Metoda ustawiająca stan komórki na planszy
    void setCellState(int row, int col, char state) {
        grid[row][col].setState(state);
    }

    // Metoda sprawdzająca, czy dane pole jest puste
    bool isCellEmpty(int row, int col) const {
        return getCellState(row, col) == EMPTY;
    }

    // Metoda sprawdzająca, czy dane pole zostało trafione
    bool isCellHit(int row, int col) const {
        return getCellState(row, col) == HIT;
    }

    // Metoda sprawdzająca, czy dane pole zostało chybione
    bool isCellMiss(int row, int col) const {
        return getCellState(row, col) == MISS;
    }

    // Metoda sprawdzająca, czy dane pole jest w granicach planszy
    bool isCellValid(int row, int col) const {
        return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
    }

    // Przeciążenie operatora strumieniowego dla wypisywania planszy
    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        os << "   ";
        for (int col = 0; col < BOARD_SIZE; col++) {
            os << std::setw(2) << col;
        }
        os << "\n";
        for (int row = 0; row < BOARD_SIZE; row++) {
            os << std::setw(2) << row;
            for (int col = 0; col < BOARD_SIZE; col++) {
                os << " " << board.getCellState(row, col);
            }
            os << "\n";
        }
        return os;
    }




};


#endif //OOP_IN_C_BOARD_H
