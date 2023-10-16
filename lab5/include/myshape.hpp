#pragma once
#include <iostream>

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

    ~Shape() {}

    void draw(sf::RenderWindow &window) const;

    void move(float speed, unsigned width, unsigned height);

    void rotate(float angle, unsigned width, unsigned height);
};
