#include "Player.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include "Board.h"
#include "Player.h"
#include "ComputerPlayer.h"

Player::Player(const std::string &name) : playerName(name), playerBoard(10), enemyBoard(10)
{
    ships.push_back(Ship("Carrier", 5));
    ships.push_back(Ship("Battleship", 4));
    ships.push_back(Ship("Cruiser", 3));
    ships.push_back(Ship("Submarine", 3));
    ships.push_back(Ship("Destroyer", 2));
}

std::string Player::getName() const
{
    return playerName;
}

std::string Player::getPlayerBoard() const
{
    return playerBoard;
}

std::string Player::getEnemyBoard() const
{
    return enemyBoard;
}

void Player::placeShips()
{
    for (const auto &ship : ships)
    {
        bool validPlacement = false;

        while (!validPlacement)
        {
            int x, y;
            char orientation;
            std::cout << "Enter the coordinates and orientation (H for horizontal, V for vertical) for your " << ship.getName() << " (length: " << ship.getLength() << "): ";
            std::cin >> x >> y >> orientation;

            bool vertical = (orientation == 'V' || orientation == 'v');
            validPlacement = playerBoard.canPlaceShip(x, y, ship.getLength(), vertical);

            if (validPlacement)
            {
                playerBoard.placeShip(x, y, ship.getLength(), vertical);
            }
            else
            {
                std::cout << "Invalid placement. Please try again.\n";
            }
        }
    }
}

void Player::attack(Player &opponent)
{
    int x, y;
    std::cout << "Enter the coordinates to attack: ";
    std::cin >> x >> y;

    if (opponent.playerBoard.isCellEmpty(x, y))
    {
        opponent.playerBoard.markCellAsMiss(x, y);
        playerBoard.markCellAsMiss(x, y);
        std::cout << "Miss!\n";
    }
    else if (opponent.playerBoard.grid[x][y] == CellState::Ship)
    {
        opponent.playerBoard.markCellAsHit(x, y);
        playerBoard.markCellAsHit(x, y);
        std::cout << "Hit!\n";
    }
    else
    {
        std::cout << "Invalid attack. Please try again.\n";
    }
}

bool Player::allShipsSunk() const
{
    return playerBoard.isAllShipsSunk();
}
