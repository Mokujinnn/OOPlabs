#pragma once

#include "myshape.hpp"

class Circle : public Shape
{
private:
    sf::Vector2f center;
    unsigned radius;

public:
    Circle();

    Circle(unsigned countOfPoints, unsigned radius, const sf::Vector2f &center);

    ~Circle() {};
};
