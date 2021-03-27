#include "Ship.hpp"

Ship::Ship(sf::Vector2i pos, Ship::Direction dir, Ship::Type type)
  : pos(pos), dir(dir), type(type)
{
    // get the ship length
    int shipLength;
    switch (type)
    {
        case Ship::Carrier:    shipLength = 5; break;
        case Ship::Battleship: shipLength = 4; break;
        case Ship::Destroyer:
        case Ship::Submarine:  shipLength = 3; break;
        case Ship::PatrolBoat: shipLength = 2; break;
    }

    // make the bounding box
    switch(dir)
    {
        case Ship::East:
            box = sf::Rect(pos.x, pos.y, pos.x + shipLength, pos.y + 1);
            break;
        case Ship::North:
            box = sf::Rect(pos.x, pos.y + 1 - shipLength, pos.x + 1, pos.y + 1);
            break;
        case Ship::West:
            box = sf::Rect(pos.x + 1 - shipLength, pos.y, pos.x + 1, pos.y + 1);
            break;
        case Ship::South:
            box = sf::Rect(pos.x, pos.y, pos.x + 1, pos.y + shipLength);
            break;
    }
}

sf::Vector2i Ship::getPos() const
{
    return pos;
}

Ship::Type Ship::getType() const
{
    return type;
}

sf::IntRect Ship::getBoundingBox() const
{
    return box;
}