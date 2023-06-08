#include "ComputerPlayer.h"
#include <random>
#include <ctime>

ComputerPlayer::ComputerPlayer(const std::string &name) : Player(name)
{
}

void ComputerPlayer::placeShips()
{
    std::default_random_engine engine(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, 9);

    for (const auto &ship : ships)
    {
        bool validPlacement = false;

        while (!validPlacement)
        {
            int x = distribution(engine);
            int y = distribution(engine);
            bool vertical = distribution(engine) % 2 == 0;

            validPlacement = playerBoard.canPlaceShip(x, y, ship.getLength(), vertical);

            if (validPlacement)
            {
                playerBoard.placeShip(x, y, ship.getLength(), vertical);
            }
        }
    }
}

void ComputerPlayer::attack(Player &opponent)
{
    std::default_random_engine engine(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, 9);

    int x, y;
    std::tie(x, y) = getRandomCoordinates();

    if (opponent.playerBoard.isCellEmpty(x, y))
    {
        opponent.playerBoard.markCellAsMiss(x, y);
        playerBoard.markCellAsMiss(x, y);
        std::cout << "Computer missed!\n";
    }
    else if (opponent.playerBoard.grid[x][y] == CellState::Ship)
    {
        opponent.playerBoard.markCellAsHit(x, y);
        playerBoard.markCellAsHit(x, y);
        std::cout << "Computer hit!\n";
    }
}

std::pair<int, int> ComputerPlayer::getRandomCoordinates() const
{
    std::default_random_engine engine(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, 9);

    int x = distribution(engine);
    int y = distribution(engine);

    return std::make_pair(x, y);
}
