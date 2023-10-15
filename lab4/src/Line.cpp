#include "Line.hpp"

Line::Line(const sf::Vector2f& p1, const sf::Vector2f& p2) : Shape(2)
{
    this->points.setPrimitiveType(sf::Lines);
    this->points[0].position = p1;
    this->points[1].position = p2;
}
