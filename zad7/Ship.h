#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship
{
public:
    Ship(const std::string &name, int length);
    std::string getName() const;
    int getLength() const;

private:
    std::string shipName;
    int shipLength;
};

#endif
