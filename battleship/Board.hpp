#ifndef BATTLESHIP_BOARD_HPP
#define BATTLESHIP_BOARD_HPP

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Ship.hpp"

class Board : public sf::Drawable, public sf::Transformable
{
public:
    Board(sf::Vector2u size);

    bool addShip(Ship& ship);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;

    sf::Vector2u size;
    std::vector<Ship> ships;
};

#endif