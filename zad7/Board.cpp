#include "Board.h"

Board::Board(int size) : boardSize(size)
{
    grid.resize(boardSize, std::vector<CellState>(boardSize, CellState::Empty));
}

void Board::placeShip(int x, int y, int length, bool vertical)
{
    for (int i = 0; i < length; ++i)
    {
        if (vertical)
        {
            grid[x + i][y] = CellState::Ship;
        }
        else
        {
            grid[x][y + i] = CellState::Ship;
        }
    }
}

bool Board::canPlaceShip(int x, int y, int length, bool vertical) const
{
    if (vertical)
    {
        if (x + length > boardSize)
        {
            return false;
        }

        for (int i = 0; i < length; ++i)
        {
            if (grid[x + i][y] != CellState::Empty)
            {
                return false;
            }
        }
    }
    else
    {
        if (y + length > boardSize)
        {
            return false;
        }

        for (int i = 0; i < length; ++i)
        {
            if (grid[x][y + i] != CellState::Empty)
            {
                return false;
            }
        }
    }

    return true;
}

bool Board::isCellEmpty(int x, int y) const
{
    return grid[x][y] == CellState::Empty;
}

void Board::markCellAsShip(int x, int y)
{
    grid[x][y] = CellState::Ship;
}

void Board::markCellAsHit(int x, int y)
{
    grid[x][y] = CellState::Hit;
}

void Board::markCellAsMiss(int x, int y)
{
    grid[x][y] = CellState::Miss;
}

bool Board::isAllShipsSunk() const
{
    for (const auto &row : grid)
    {
        for (const auto &cell : row)
        {
            if (cell == CellState::Ship)
            {
                return false;
            }
        }
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    for (const auto &row : board.grid)
    {
        for (const auto &cell : row)
        {
            switch (cell)
            {
                case CellState::Empty:
                    os << ".";
                    break;
                case CellState::Ship:
                    os << "@";
                    break;
                case CellState::Hit:
                    os << "X";
                    break;
                case CellState::Miss:
                    os << "O";
                    break;
            }
            os << " ";
        }
        os << "\n";
    }

     return os;

}
