#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "battleship/Config.hpp"
#include "battleship/Board.hpp"
#include "battleship/Cursor.hpp"
#include "battleship/Ship.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(TILE_SIZE * 10, TILE_SIZE * 10), "hoohacks2021");
    window.setKeyRepeatEnabled(false);

    Board board(sf::Vector2u(10, 10));
    board.addShip(Ship(sf::Vector2i(4, 4), Ship::East, Ship::Carrier));

    Cursor cursor;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                    cursor.move(sf::Vector2i(1, 0));
                if (event.key.code == sf::Keyboard::Up)
                    cursor.move(sf::Vector2i(0, -1));
                if (event.key.code == sf::Keyboard::Left)
                    cursor.move(sf::Vector2i(-1, 0));
                if (event.key.code == sf::Keyboard::Down)
                    cursor.move(sf::Vector2i(0, 1));
            }
        }

        window.clear();
        window.draw(board);
        window.draw(cursor);
        window.display();
    }

    return 0;
}