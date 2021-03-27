#include "Board.hpp"

#include <algorithm>

Board::Board(sf::Vector2u size)
  : size(size)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(size.x * size.y * 4);

    for (unsigned int i = 0; i < size.x; ++i)
    {
        for (unsigned int j = 0; j < size.y; ++j)
        {
            sf::Vertex* quad = &m_vertices[(i + j * size.x) * 4];

            quad[0].position = sf::Vector2f(i * 16, j * 16);
            quad[1].position = sf::Vector2f((i + 1) * 16, j * 16);
            quad[2].position = sf::Vector2f((i + 1) * 16, (j + 1) * 16);
            quad[3].position = sf::Vector2f(i * 16, (j + 1) * 16);

            quad[0].color = sf::Color::Blue;
            quad[1].color = sf::Color::Blue;
            quad[2].color = sf::Color::Blue;
            quad[3].color = sf::Color::Blue;
        }
    }
}

bool Board::addShip(Ship& ship)
{
    // check to make sure there aren't any ships of the same type already on the board
    for (int i = 0; i < ships.size(); ++i)
        if (ships[i].getType() == ship.getType())
            return false;

    // get the ship length
    int shipLength;
    switch (ship.getType())
    {
        case Ship::Carrier:    shipLength = 5; break;
        case Ship::Battleship: shipLength = 4; break;
        case Ship::Destroyer:
        case Ship::Submarine:  shipLength = 3; break;
        case Ship::PatrolBoat: shipLength = 2; break;
        default:               return false;
    }

    ships.push_back(ship);

    return true;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(m_vertices, states);
}