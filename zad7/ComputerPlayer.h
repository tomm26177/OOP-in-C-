#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player
{
public:
    ComputerPlayer(const std::string &name);
    void placeShips() override;
    void attack(Player &opponent) override;

private:
    std::pair<int, int> getRandomCoordinates() const;
};

#endif
