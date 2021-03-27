#ifndef BATTLESHIP_CURSOR_HPP
#define BATTLESHIP_CURSOR_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Cursor : public sf::Drawable, public sf::Transformable
{
public:
    Cursor();
    Cursor(sf::Vector2i pos);

    void move(sf::Vector2i offset);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void initVertices();
    sf::VertexArray m_vertices;

    sf::Vector2i pos;
};

#endif