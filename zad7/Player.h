#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Ship.h"

class Player
{
public:
    virtual void placeShips();
    virtual void attack(Player &opponent);
    Player(const std::string &name);
    std::string getName() const ;
    std::string getPlayerBoard() const;
    std::string getEnemyBoard() const;
    bool allShipsSunk() const;

public:
    std::string playerName;
    Board playerBoard;
    Board enemyBoard;
    std::vector<Ship> ships;
};

#endif
