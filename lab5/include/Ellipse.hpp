#pragma once

#include "myshape.hpp"

class Ellipse : public Shape
{
private:

    sf::Vector2f f1;
    sf::Vector2f f2;
    
public:
    Ellipse(unsigned countOfPoints, const sf::Vector2f &center, float a, float b);

    ~Ellipse() {}
};



