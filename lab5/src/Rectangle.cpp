#include "Rectangle.hpp"

Rectangle::Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2) : Shape(4)
{
    this->points.setPrimitiveType(sf::Quads);

    this->points[0].position = p1;
    this->points[1].position = sf::Vector2f(p2.x, p1.y);
    this->points[2].position = p2;
    this->points[3].position = sf::Vector2f(p1.x, p2.y);
}