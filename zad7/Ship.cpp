#include "Ship.h"

Ship::Ship(const std::string &name, int length) : shipName(name), shipLength(length)
{
}

std::string Ship::getName() const
{
    return shipName;
}

int Ship::getLength() const
{
    return shipLength;
}
