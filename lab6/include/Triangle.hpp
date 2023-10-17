#pragma once

#include "myshape.hpp"

class Triangle : public Shape
{
private:
    
public:
    Triangle(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3);

    ~Triangle() {}
};


