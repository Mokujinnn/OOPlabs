#include <vector>

#include "myshape.hpp"

Shape::Shape() : moveDerection(sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100)),
                 num(0)
{
}

Shape::Shape(unsigned num) : moveDerection(sf::Vector2f(rand() % 200 - 100, rand() % 200 - 100)),
                             num(num)
{
    this->points.resize(num);
}

void Shape::draw(sf::RenderWindow &window) const
{
    window.draw(points);
}

void Shape::move(float speed, unsigned width, unsigned height)
{
    std::vector<sf::Vector2f> p;

    sf::Vector2f coordinateShift = speed * moveDerection;

    bool flag = true;

    sf::Vector2f tmp(0, 0);

    for (int i = 0; i < num; i++)
    {
        sf::Vector2f newPos = this->points[i].position;

        newPos = sf::Vector2f(newPos + coordinateShift);

        if (newPos.x > width || newPos.x < 0)
        {
            flag = false;
            float x = 0;
            if (newPos.x > width)
                x = width - this->points[i].position.x;
            else
                x = 0 - this->points[i].position.x;
            if (tmp.x == 0 || abs(tmp.x) > abs(x))
                tmp.x = x;
        }
        else if (newPos.y > height || newPos.y < 0)
        {
            flag = false;
            float y = 0;
            if (newPos.y > height)
                y = height - this->points[i].position.y;
            else
                y = 0 - this->points[i].position.y;
            if (tmp.y == 0 || (abs(tmp.y) > abs(y)))
                tmp.y = y;
        }
        else
        {
            p.push_back(newPos);
        }
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
        for (int i = 0; i < this->num; i++)
        {
            points[i].position += tmp;
        }
    }
    else
    {
        for (int i = 0; i < this->num; i++)
        {
            points[i].position = p[i];
        }
    }
}