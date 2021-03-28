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

            quad[0].position = sf::Vector2f(i * TILE_SIZE, j * TILE_SIZE);
            quad[1].position = sf::Vector2f((i + 1) * TILE_SIZE, j * TILE_SIZE);
            quad[2].position = sf::Vector2f((i + 1) * TILE_SIZE, (j + 1) * TILE_SIZE);
            quad[3].position = sf::Vector2f(i * TILE_SIZE, (j + 1) * TILE_SIZE);

            quad[0].color = sf::Color::Blue;
            quad[1].color = sf::Color::Blue;
            quad[2].color = sf::Color::Blue;
            quad[3].color = sf::Color::Blue;
        }
    }
}

bool Board::addShip(Ship ship)
{
    // check to make sure there aren't any ships of the same type already on the board
    for (int i = 0; i < ships.size(); ++i)
        if (ships[i].getType() == ship.getType())
            return false;

    // check to make sure the ship is on the board
    if (ship.getBoundingBox().left < 0 || ship.getBoundingBox().left + ship.getBoundingBox().width > size.x)
        return false;
    if (ship.getBoundingBox().top < 0 || ship.getBoundingBox().top + ship.getBoundingBox().height > size.y)
        return false;

    // add ships to the ship list
    ships.push_back(ship);

    // draw the ship
    for (int i = ship.getBoundingBox().left; i < ship.getBoundingBox().left + ship.getBoundingBox().width; ++i)
    {
        for (int j = ship.getBoundingBox().top; j < ship.getBoundingBox().top + ship.getBoundingBox().height; ++j)
        {
            sf::Vertex* quad = &m_vertices[(i + j * size.x) * 4];

            quad[0].color = sf::Color::Red;
            quad[1].color = sf::Color::Red;
            quad[2].color = sf::Color::Red;
            quad[3].color = sf::Color::Red;
        }
    }

    return true;
}