#include "Cursor.hpp"
#include "Config.hpp"

Cursor::Cursor()
  : pos(0, 0)
{
    setPosition(0, 0);
    initVertices();
}

Cursor::Cursor(sf::Vector2i pos)
  : pos(pos)
{
    setPosition(sf::Vector2f(pos * TILE_SIZE));
    initVertices();
}

void Cursor::move(sf::Vector2i offset)
{
    pos += offset;
    setPosition(sf::Vector2f(pos * TILE_SIZE));
}

void Cursor::initVertices()
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    sf::Vertex* quad = &m_vertices[0];

    quad[0].position = sf::Vector2f(0, 0);
    quad[1].position = sf::Vector2f(TILE_SIZE, 0);
    quad[2].position = sf::Vector2f(TILE_SIZE, TILE_SIZE);
    quad[3].position = sf::Vector2f(0, TILE_SIZE);

    quad[0].color = sf::Color::Black;
    quad[1].color = sf::Color::Black;
    quad[2].color = sf::Color::Black;
    quad[3].color = sf::Color::Black;
}

void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(m_vertices, states);
}