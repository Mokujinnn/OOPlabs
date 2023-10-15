#pragma once

#include "myshape.hpp"

class Line : public Shape
{
private:

public:

    Line(const sf::Vector2f& p1, const sf::Vector2f& p2);

    ~Line() {}
};


