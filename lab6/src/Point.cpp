#include "Point.hpp"

#include <iostream>

Point::Point(unsigned width, unsigned height) : Shape(1)
{
    this->points.setPrimitiveType(sf::Points);
    this->points[0] = sf::Vector2f(rand() % width, rand() % height);
}

void Point::move(float speed, unsigned width, unsigned height)
{
    sf::Vector2f coordinateShift = speed * moveDerection;
    sf::Vector2f tmp(0, 0);

    sf::Vector2f newPos = this->points[0].position;

    newPos = sf::Vector2f(newPos + coordinateShift);

    bool flag = true;
    if (newPos.x > width || newPos.x < 0)
    {
        flag = false;
        float x = 0;
        if (newPos.x > width)
            x = width - this->points[0].position.x;
        else
            x = 0 - this->points[0].position.x;
        if (tmp.x == 0 || abs(tmp.x) > abs(x))
            tmp.x = x;
    }
    else if (newPos.y > height || newPos.y < 0)
    {
        flag = false;
        float y = 0;
        if (newPos.y > height)
            y = height - this->points[0].position.y;
        else
            y = 0 - this->points[0].position.y;
        if (tmp.y == 0 || (abs(tmp.y) > abs(y)))
            tmp.y = y;
    }

    if (!flag)
    {
        if (tmp.x != 0 && tmp.y == 0)
        {
            this->moveDerection.x *= -1;
            tmp.y = coordinateShift.y;
        }
        else if (tmp.x == 0 && tmp.y != 0)
        {
            this->moveDerection.y *= -1;
            tmp.x = coordinateShift.x;
        }
        else
        {
            this->moveDerection.x *= -1;
            this->moveDerection.y *= -1;
        }
        points[0].position += tmp;
    }
    else
    {
        points[0].position = newPos;
    }
}