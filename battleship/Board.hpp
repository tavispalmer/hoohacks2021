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

    void drawOpponent(sf::RenderWindow& window);
    void drawPlayer(sf::RenderWindow& window);

    bool getOccupied(unsigned int x, unsigned int y) const;

    bool addMarker(unsigned int x, unsigned int y);
    
private:
    sf::VertexArray player_vertices;
    sf::VertexArray opponent_vertices;
    std::vector<Ship> ships;
    std::vector<bool> markers;

    sf::Vector2u size;
};

#endif

