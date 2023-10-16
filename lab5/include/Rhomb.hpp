#pragma once

#include "myshape.hpp"

class Rhomb : public Shape
{
private:

public:
    Rhomb(const sf::Vector2f& center, float d1, float d2);

    ~Rhomb() {}
};
