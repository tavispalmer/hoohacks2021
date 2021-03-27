#ifndef BATTLESHIP_BOARD_HPP
#define BATTLESHIP_BOARD_HPP

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Ship.hpp"

class Board
{
public:
    Board(sf::Vector2u size);

    bool addShip(Ship ship);

    void drawWithShips(sf::RenderWindow& window);
    void drawWithoutShips(sf::RenderWindow& window);

private:
    sf::VertexArray m_vertices;

    sf::Vector2u size;
    std::vector<Ship> ships;
};

#endif