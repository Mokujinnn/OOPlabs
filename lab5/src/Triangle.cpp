#include "Triangle.hpp"

Triangle::Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3) : Shape(3)
{
    this->points.setPrimitiveType(sf::Triangles);

    this->points[0].position = p1;
    this->points[1].position = p2;
    this->points[2].position = p3;
}