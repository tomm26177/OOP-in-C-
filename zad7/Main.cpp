#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

enum class CellState { Empty, Ship, Miss, Hit };

class Board {
protected:
    int size_;
    std::vector<std::vector<CellState>> cells_;

public:
    Board(int size) : size_(size) {
        cells_.resize(size_, std::vector<CellState>(size_, CellState::Empty));
    }

    int getSize() const {
        return size_;
    }

    CellState getCellState(int row, int col) const {
        return cells_[row][col];
    }

    void setCellState(int row, int col, CellState state) {
        cells_[row][col] = state;
    }

    void display(bool showShips) const {
        std::cout << "   ";
        for (int col = 0; col < size_; ++col) {
            std::cout << col << " ";
        }
        std::cout << std::endl;

        for (int row = 0; row < size_; ++row) {
            std::cout << row << " ";
            for (int col = 0; col < size_; ++col) {
                char symbol;
                switch (cells_[row][col]) {
                    case CellState::Empty:
                        symbol = showShips ? '-' : ' ';
                        break;
                    case CellState::Ship:
                        symbol = showShips ? 'S' : ' ';
                        break;
                    case CellState::Miss:
                        symbol = '*';
                        break;
                    case CellState::Hit:
                        symbol = 'X';
                        break;
                    default:
                        symbol = ' ';
                        break;
                }
                std::cout << symbol << " ";
            }
            std::cout << std::endl;
        }
    }
};

class PlayerBoard : public Board {
public:
    PlayerBoard(int size) : Board(size) {}
};

class EnemyBoard : public Board {
public:
    EnemyBoard(int size) : Board(size) {}
};

class Ship {
protected:
    std::string name_;
    int size_;
    int hits_;

public:
    Ship(const std::string& name, int size) : name_(name), size_(size), hits_(0) {}

    const std::string& getName() const {
        return name_;
    }

    int getSize() const {
        return size_;
    }

    int getHits() const {
        return hits_;
    }

    bool isSunk() const {
        return hits_ >= size_;
    }

    void hit() {
        ++hits_;
    }
};

class Carrier : public Ship {
public:
    Carrier() : Ship("Carrier", 5) {}
};

class Battleship : public Ship {
public:
    Battleship() : Ship("Battleship", 4) {}
};

class Cruiser : public Ship {
public:
    Cruiser() : Ship("Cruiser", 3) {}
};

class Submarine : public Ship {
public:
    Submarine() : Ship("Submarine", 3) {}
};

class Destroyer : public Ship {
public:
    Destroyer() : Ship("Destroyer", 2) {}
};

class Game {
private:
    int boardSize_;
    PlayerBoard playerBoard_;
    EnemyBoard enemyBoard_;
    std::vector<Ship*> playerShips_;
    std::vector<Ship*> enemyShips_;
    std::ofstream outputFile_;

public:
    Game(int boardSize) : boardSize_(boardSize), playerBoard_(boardSize), enemyBoard_(boardSize) {
        playerShips_ = { new Carrier(), new Battleship(), new Cruiser(), new Submarine(), new Destroyer() };
        enemyShips_ = { new Carrier(), new Battleship(), new Cruiser(), new Submarine(), new Destroyer() };
        outputFile_.open("Board.txt");
    }

    ~Game() {
        for (Ship* ship : playerShips_) {
            delete ship;
        }
        for (Ship* ship : enemyShips_) {
            delete ship;
        }
        outputFile_.close();
    }

    void placeShipsRandomly(Board& board, const std::vector<Ship*>& ships) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, board.getSize() - 1);

        for (Ship* ship : ships) {
            bool placed = false;
            while (!placed) {
                int row = dis(gen);
                int col = dis(gen);
                bool horizontal = std::rand() % 2 == 0;

                if (isValidPlacement(board, row, col, ship->getSize(), horizontal)) {
                    placeShip(board, ship, row, col, horizontal);
                    placed = true;
                }
            }
        }
    }

    bool isValidPlacement(const Board& board, int row, int col, int size, bool horizontal) const {
        if (horizontal) {
            if (col + size > board.getSize()) {
                return false;
            }

            for (int c = col; c < col + size; ++c) {
                if (board.getCellState(row, c) != CellState::Empty) {
                    return false;
                }
            }
        } else {
            if (row + size > board.getSize()) {
                return false;
            }

            for (int r = row; r < row + size; ++r) {
                if (board.getCellState(r, col) != CellState::Empty) {
                    return false;
                }
            }
        }

        return true;
    }

    void placeShip(Board& board, Ship* ship, int row, int col, bool horizontal) {
        int size = ship->getSize();
        if (horizontal) {
            for (int c = col; c < col + size; ++c) {
                board.setCellState(row, c, CellState::Ship);
            }
        } else {
            for (int r = row; r < row + size; ++r) {
                board.setCellState(r, col, CellState::Ship);
            }
        }
    }

    void displayBoards() const {
        std::cout << "Player Board:\n";
        playerBoard_.display(true);
        std::cout << "\nEnemy Board:\n";
        enemyBoard_.display(false);
    }

    void playerTurn() {
        int row, col;
        bool validShot = false;

        while (!validShot) {
            std::cout << "Enter coordinates for your shot (row col): ";
            std::cin >> row >> col;

            if (row < 0 || row >= boardSize_ || col < 0 || col >= boardSize_) {
                std::cout << "Invalid coordinates! Please try again.\n";
            } else if (enemyBoard_.getCellState(row, col) != CellState::Empty) {
                std::cout << "You've already shot at this position! Please try again.\n";
            } else {
                validShot = true;
            }
        }

        CellState result = checkShot(enemyBoard_, row, col);
        enemyBoard_.setCellState(row, col, result);
        displayShotResult("Player", row, col, result);
        outputFile_ << "Player: Shot at (" << row << ", " << col << "), Result: " << cellStateToString(result) << std::endl;
    }

    void enemyTurn() {
        int row, col;
        bool validShot = false;

        while (!validShot) {
            row = std::rand() % boardSize_;
            col = std::rand() % boardSize_;

            if (playerBoard_.getCellState(row, col) == CellState::Empty) {
                validShot = true;
            }
        }

        CellState result = checkShot(playerBoard_, row, col);
        playerBoard_.setCellState(row, col, result);
        displayShotResult("Enemy", row, col, result);
        outputFile_ << "Enemy: Shot at (" << row << ", " << col << "), Result: " << cellStateToString(result) << std::endl;
    }

    CellState checkShot(const Board& board, int row, int col) const {
        switch (board.getCellState(row, col)) {
            case CellState::Empty:
                return CellState::Miss;
            case CellState::Ship:
                return CellState::Hit;
            default:
                return CellState::Empty;
        }
    }

    void displayShotResult(const std::string& player, int row, int col, CellState result) const {
        std::string message;
        switch (result) {
            case CellState::Miss:
                message = "missed!";
                break;
            case CellState::Hit:
                message = "hit a ship!";
                break;
            default:
                message = "invalid result!";
                break;
        }
        std::cout << player << " shot at (" << row << ", " << col << ") and " << message << std::endl;
    }

    std::string cellStateToString(CellState state) const {
        switch (state) {
            case CellState::Empty:
                return "Empty";
            case CellState::Ship:
                return "Ship";
            case CellState::Miss:
                return "Miss";
            case CellState::Hit:
                return "Hit";
            default:
                return "Unknown";
        }
    }

    bool isGameOver(const Board& board, const std::vector<Ship*>& ships) const {
        for (Ship* ship : ships) {
            if (!ship->isSunk()) {
                return false;
            }
        }
        return true;
    }

    void saveBoardsToFile() const {
        std::ofstream outputFile("boards.txt");
        if (outputFile.is_open()) {
            outputFile << "Player Board:\n";
            saveBoardToFile(outputFile, playerBoard_);
            outputFile << "\nEnemy Board:\n";
            saveBoardToFile(outputFile, enemyBoard_);
            outputFile.close();
        } else {
            std::cout << "Failed to save boards to file!" << std::endl;
        }
    }

    void saveBoardToFile(std::ofstream& outputFile, const Board& board) const {
        for (int row = 0; row < board.getSize(); ++row) {
            for (int col = 0; col < board.getSize(); ++col) {
                outputFile << static_cast<char>(board.getCellState(row, col));
            }
            outputFile << '\n';
        }
    }

    void play() {
        placeShipsRandomly(playerBoard_, playerShips_);
        placeShipsRandomly(enemyBoard_, enemyShips_);

        while (true) {
            displayBoards();

            playerTurn();
            if (isGameOver(enemyBoard_, enemyShips_)) {
                std::cout << "Congratulations! You won the game!" << std::endl;
                outputFile_ << "Game Over: Player wins!" << std::endl;
                break;
            }

            enemyTurn();
            if (isGameOver(playerBoard_, playerShips_)) {
                std::cout << "Game over! You lost the game." << std::endl;
                outputFile_ << "Game Over: Enemy wins!" << std::endl;
                break;
            }
        }

        saveBoardsToFile();
    }
};

int main() {
    int boardSize;
    std::cout << "Enter the size of the board: ";
    std::cin >> boardSize;

    Game game(boardSize);
    game.play();

    return 0;
}
