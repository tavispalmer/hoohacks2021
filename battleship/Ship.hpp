#ifndef BATTLESHIP_SHIP_HPP
#define BATTLESHIP_SHIP_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Ship : public sf::Drawable, public sf::Transformable
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
        PatrolBoat,
        TypeCount
    };

    Ship(sf::Vector2i pos, Direction dir, Type type);

    sf::Vector2i getPos() const;
    Direction getDirection() const;
    Type getType() const;
    sf::IntRect getBoundingBox() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Vector2i pos;
    Direction dir;
    Type type;
    sf::IntRect box;
};

#endif