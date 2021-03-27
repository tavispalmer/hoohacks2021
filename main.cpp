#include <iostream>
#include <exception>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "battleship/Config.hpp"
#include "battleship/Board.hpp"
#include "battleship/Controller.hpp"
#include "battleship/Cursor.hpp"
#include "battleship/Ship.hpp"

sf::RenderWindow window(sf::VideoMode(TILE_SIZE * 10, TILE_SIZE * 10), "hoohacks2021");
Board board(sf::Vector2u(10, 10));
Controller controller;
Cursor cursor;

enum GameState
{
    pickShips,
    playerMove
} gameState;

/// Get the player's ships
void pickShips()
{
    static Ship::Type shipType = Ship::Carrier;
    if (shipType >= Ship::TypeCount) {
        printf("Incorrect Placement. Please try again!");
    }
    else {
        shipType = static_cast<Ship::Type>(shipType + 1);
    }
        // todo
}

/// Gets this player's move
void getPlayerMove()
{
    // Move the cursor
    if (controller.rightPressed)
        cursor.move(sf::Vector2i(1, 0));
    if (controller.upPressed)
        cursor.move(sf::Vector2i(0, -1));
    if (controller.leftPressed)
        cursor.move(sf::Vector2i(-1, 0));
    if (controller.downPressed)
        cursor.move(sf::Vector2i(0, 1));

    window.draw(board);
    window.draw(cursor);
}


/// Method to handle window events
void handleEvents(sf::RenderWindow& window, Controller& controller)
{
    controller.rightPressed = false;
    controller.upPressed = false;
    controller.leftPressed = false;
    controller.downPressed = false;

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        
        // Keyboard input handling
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Right:
                    controller.right = true;
                    controller.rightPressed = true;
                    break;
                case sf::Keyboard::Up:
                    controller.up = true;
                    controller.upPressed = true;
                    break;
                case sf::Keyboard::Left:
                    controller.left = true;
                    controller.leftPressed = true;
                    break;
                case sf::Keyboard::Down:
                    controller.down = true;
                    controller.downPressed = true;
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Right:
                    controller.right = false;
                    break;
                case sf::Keyboard::Up:
                    controller.up = false;
                    break;
                case sf::Keyboard::Left:
                    controller.left = false;
                    break;
                case sf::Keyboard::Down:
                    controller.down = false;
                    break;
                default:
                    break;
            }
        }
    }
}

/// Main method
int main()
{
    window.setKeyRepeatEnabled(false);
    board.addShip(Ship(sf::Vector2i(4, 4), Ship::East, Ship::Carrier));
    gameState = playerMove;

    while (window.isOpen())
    {
        handleEvents(window, controller);

        window.clear();

        switch (gameState)
        {
            case playerMove: getPlayerMove(); break;
            default: throw std::exception(); break;
        }

        window.display();
    }

    return 0;
}