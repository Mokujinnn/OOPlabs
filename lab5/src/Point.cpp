#include "Point.hpp"

#include <iostream>

Point::Point(unsigned width, unsigned height) : Shape(1)
{
    this->points.setPrimitiveType(sf::Points);
    this->points[0] = sf::Vector2f(rand() % width, rand() % height);
}
