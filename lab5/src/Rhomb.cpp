#include "Rhomb.hpp"

Rhomb::Rhomb(const sf::Vector2f &center, float d1, float d2) : Shape(4)
{
    this->points.setPrimitiveType(sf::Quads);

    this->points[0].position = sf::Vector2f(center.x, center.y + d1 / 2);
    this->points[1].position = sf::Vector2f(center.x + d2 / 2, center.y);
    this->points[2].position = sf::Vector2f(center.x, center.y - d1 / 2);
    this->points[3].position = sf::Vector2f(center.x - d2 / 2, center.y);
}