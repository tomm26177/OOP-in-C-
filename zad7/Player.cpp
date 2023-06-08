//
// Created by 48510 on 08.06.2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "Board.cpp"
class Player {
private:
    std::string name;
    Board playerBoard;
    Board enemyBoard;
    std::vector<Ship*> ships;
public:
    Player(const std::string& n) : name(n) {
        ships.push_back(new Battleship());
        ships.push_back(new Cruiser());
        ships.push_back(new Cruiser());
        ships.push_back(new Destroyer());
        ships.push_back(new PatrolBoat());
    }

    ~Player() {
        for (Ship* ship : ships) {
            delete ship;
        }
    }

    // Metoda zwracająca nazwę gracza
    std::string getName() const {
        return name;
    }

    // Metoda umieszczająca statki gracza na planszy
    void placeShips() {
        for (Ship* ship : ships) {
            ship->place(playerBoard);
        }
    }

    // Metoda sprawdzająca, czy wszystkie statki przeciwnika zostały zatopione
    bool allShipsSunk() const {
        for (const Ship* ship : ships) {
            if (!ship->isSunk()) {
                return false;
            }
        }
        return true;
    }

    // Metoda atakująca przeciwnika
    void attack(Player& enemy) {
        std::srand(std::time(nullptr));
        int row, col;
        bool attacked = false;
        while (!attacked) {
            row = std::rand() % Board::BOARD_SIZE;
            col = std::rand() % Board::BOARD_SIZE;
            if (enemy.enemyBoard.isCellValid(row, col)) {
                if (enemy.enemyBoard.isCellEmpty(row, col)) {
                    enemy.enemyBoard.setCellState(row, col, Board::MISS);
                    attacked = true;
                    std::cout << name << " misses!\n";
                }
                else if (enemy.enemyBoard.isCellHit(row, col)) {
                    continue;  // Already hit, try again
                }
                else {
                    enemy.enemyBoard.setCellState(row, col, Board::HIT);
                    attacked = true;
                    std::cout << name << " hits!\n";
                    for (Ship* ship : enemy.ships) {
                        for (int i = 0; i < ship->getSize(); i++) {
                            int shipRow, shipCol;
                            shipRow = col - i;
                            shipCol = row;
                            if (enemy.enemyBoard.isCellValid(shipRow, shipCol) && enemy.enemyBoard.getCellState(shipRow, shipCol) != Board::HIT) {
                                enemy.enemyBoard.setCellState(shipRow, shipCol, Board::HIT);
                                ship->hit();
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Przeciążenie operatora strumieniowego dla wypisywania plansz gracza
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Player: " << player.name << "\n";
        os << "Your Board:\n" << player.playerBoard << "\n";
        os << "Enemy Board:\n" << player.enemyBoard << "\n";
        return os;
    }
};
