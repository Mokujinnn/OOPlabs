#pragma once

#include "myshape.hpp"

class Rectangle : public Shape
{
private:

public:
    Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2);

    ~Rectangle() {}
};
