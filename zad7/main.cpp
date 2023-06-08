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

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assuming POSIX
    std::system("clear");
#endif
}

int main()
{
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Player player(playerName);
    ComputerPlayer computer("Computer");

    player.placeShips();
    computer.placeShips();

    while (!player.allShipsSunk() && !computer.allShipsSunk())
    {
        clearScreen();
        std::cout << "----- " << playerName << "'s Turn -----\n";
        std::cout << "Your Board:\n" << player.getPlayerBoard() << "\n";
        std::cout << "Enemy Board:\n" << player.getEnemyBoard() << "\n";

        player.attack(computer);
        std::cout << "\n";

        clearScreen();
        std::cout << "----- Computer's Turn -----\n";
        std::cout << "Your Board:\n" << player.getPlayerBoard() << "\n";
        std::cout << "Enemy Board:\n" << player.getEnemyBoard() << "\n";

        computer.attack(player);
        std::cout << "\n";
    }

    if (player.allShipsSunk())
    {
        std::cout << "Game Over! Computer wins!\n";
    }
    else
    {
        std::cout << "Game Over! " << playerName << " wins!\n";
    }

    std::ofstream file("boards.txt");
    if (file.is_open())
    {
        file << "Player: " << player.getName() << "\n";
        file << "Player Board:\n" << player.getPlayerBoard() << "\n";
        file << "Enemy Board:\n" << player.getEnemyBoard() << "\n";
        file << "Computer: " << computer.getName() << "\n";
        file << "Player Board:\n" << computer.getPlayerBoard() << "\n";
        file << "Enemy Board:\n" << computer.getEnemyBoard() << "\n";
        file.close();
        std::cout << "Boards saved to 'boards.txt'.\n";
    }
    else
    {
        std::cout << "Failed to save boards to file.\n";
    }

    return 0;
}
