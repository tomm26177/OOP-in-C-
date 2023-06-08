#include <iostream>
#include <vector>
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
                        symbol = 'M';
                        break;
                    case CellState::Hit:
                        symbol = 'X';
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

    void placeShipsRandomly() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, size_ - 1);

        int shipCount = 0;
        while (shipCount < 5) {
            int row = dis(gen);
            int col = dis(gen);

            if (cells_[row][col] == CellState::Empty) {
                cells_[row][col] = CellState::Ship;
                shipCount++;
            }
        }
    }
};

class ComputerBoard : public Board {
public:
    ComputerBoard(int size) : Board(size) {}

    void placeShipsRandomly() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, size_ - 1);

        int shipCount = 0;
        while (shipCount < 5) {
            int row = dis(gen);
            int col = dis(gen);

            if (cells_[row][col] == CellState::Empty) {
                cells_[row][col] = CellState::Ship;
                shipCount++;
            }
        }
    }

    std::pair<int, int> generateRandomShot() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, size_ - 1);

        int row = dis(gen);
        int col = dis(gen);

        return std::make_pair(row, col);
    }
};

class Game {
private:
    PlayerBoard playerBoard_;
    ComputerBoard computerBoard_;

public:
    Game(int boardSize) : playerBoard_(boardSize), computerBoard_(boardSize) {}

    void start() {
        playerBoard_.placeShipsRandomly();
        computerBoard_.placeShipsRandomly();

        while (true) {
            std::cout << "Player's turn:" << std::endl;
            playerTurn();
            if (checkGameOver()) {
                std::cout << "Congratulations! You have won the game!" << std::endl;
                break;
            }

            std::cout << "Computer's turn:" << std::endl;
            computerTurn();
            if (checkGameOver()) {
                std::cout << "Game over! The computer has won." << std::endl;
                break;
            }
        }
    }

    void playerTurn() {
        int row, col;
        do {
            std::cout << "Enter row and column for your shot: ";
            std::cin >> row >> col;
        } while (!isValidShot(row, col));

        processShot(row, col, computerBoard_);
        playerBoard_.display(false);
    }

    void computerTurn() {
        std::pair<int, int> shot = computerBoard_.generateRandomShot();
        int row = shot.first;
        int col = shot.second;

        processShot(row, col, playerBoard_);
        computerBoard_.display(true);
    }

    bool isValidShot(int row, int col) const {
        if (row < 0 || row >= playerBoard_.getSize() || col < 0 || col >= playerBoard_.getSize()) {
            std::cout << "Invalid shot! Please enter valid coordinates." << std::endl;
            return false;
        }

        CellState cellState = playerBoard_.getCellState(row, col);
        if (cellState == CellState::Miss || cellState == CellState::Hit) {
            std::cout << "You have already shot at this location! Please choose another one." << std::endl;
            return false;
        }

        return true;
    }

    void processShot(int row, int col, Board& board) {
        CellState cellState = board.getCellState(row, col);
        if (cellState == CellState::Ship) {
            std::cout << "Hit!" << std::endl;
            board.setCellState(row, col, CellState::Hit);
        } else {
            std::cout << "Miss!" << std::endl;
            board.setCellState(row, col, CellState::Miss);
        }
    }

    bool checkGameOver() const {
        for (int row = 0; row < playerBoard_.getSize(); ++row) {
            for (int col = 0; col < playerBoard_.getSize(); ++col) {
                if (playerBoard_.getCellState(row, col) == CellState::Ship) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int boardSize;
    std::cout << "Enter the size of the board: ";
    std::cin >> boardSize;

    Game game(boardSize);
    game.start();

    return 0;
}
