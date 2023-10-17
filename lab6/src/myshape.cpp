#include <vector>

#include <cmath>

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

void Shape::setColor(const sf::Color &clr)
{
    for (int i = 0; i < this->num; i++)
    {
        this->points[i].color = clr;
    }
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

void Shape::rotate(float angle)
{
    sf::Vector2f center(0, 0);

    if (this->num > 4)
    {
        for (int i = 1; i < this->num - 1; i++)
        {
            center += this->points[i].position;
        }
        center = sf::Vector2f(center.x / (this->num - 2), center.y / (this->num - 2));
    }
    else
    {
        for (int i = 0; i < this->num; i++)
        {
            center += this->points[i].position;
        }
        center = sf::Vector2f(center.x / (this->num), center.y / (this->num));
    }

    for (int i = 0; i < this->num; i++)
    {
        float x1 = this->points[i].position.x - center.x;
        float y1 = this->points[i].position.y - center.y;

        float x = x1 * cos(angle) - y1 * sin(angle);
        float y = y1 * cos(angle) + x1 * sin(angle);

        this->points[i].position = sf::Vector2f(x + center.x, y + center.y);
    }
}