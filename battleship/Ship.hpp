#ifndef BATTLESHIP_SHIP_HPP
#define BATTLESHIP_SHIP_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Ship
{
public:

    enum Direction
    {
        East,
        North,
        West,
        South
    };

    enum Type
    {
        Carrier,
        Battleship,
        Destroyer,
        Submarine,
        PatrolBoat
    };

    Ship(sf::Vector2i pos, Direction dir, Type type);

    sf::Vector2i getPos() const;
    Direction getDirection() const;
    Type getType() const;
    sf::IntRect getBoundingBox() const;

private:
    sf::IntRect box;

    sf::Vector2i pos;
    Direction dir;
    Type type;
};

#endif