#pragma once
#include <iostream>
#include <cmath>

#include "SFML/Graphics.hpp"

class Shape
{
protected:
    sf::Vector2f moveDerection;
    sf::VertexArray points;
    unsigned num;

public:
    Shape();

    Shape(unsigned num);

    virtual ~Shape() {}

    void draw(sf::RenderWindow &window) const;

    virtual void move(float speed, unsigned width, unsigned height);

    virtual void rotate(float angle, unsigned width, unsigned height);
};
