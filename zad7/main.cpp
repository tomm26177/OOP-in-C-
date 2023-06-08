#include <iostream>




int main(){
    std::string playerName;
    std::cout << "Enter your name: ";
    std::cin >> playerName;

    Player player(playerName);
    Player computer("Computer");

    player.placeShips();
    computer.placeShips();

    while (true) {
        std::cout << player << "\n";

        if (player.allShipsSunk()) {
            std::cout << "Game Over! Computer wins!\n";
            break;
        }

        player.attack(computer);
        std::cout << "\n";

        if (computer.allShipsSunk()) {
            std::cout << "Game Over! " << playerName << " wins!\n";
            break;
        }

        computer.attack(player);
        std::cout << "\n";
    }

    // Zapisanie planszy do pliku
    std::ofstream file("boards.txt");
    if (file.is_open()) {
        file << "Player: " << player.getName() << "\n";
        file << "Player Board:\n" << player.playerBoard << "\n";
        file << "Enemy Board:\n" << player.enemyBoard << "\n";
        file << "Computer: " << computer.getName() << "\n";
        file << "Player Board:\n" << computer.playerBoard << "\n";
        file << "Enemy Board:\n" << computer.enemyBoard << "\n";
        file.close();
        std::cout << "Boards saved to 'boards.txt'.\n";
    }
    else {
        std::cout << "Failed to save boards to file.\n";
    }

    return 0;


}

