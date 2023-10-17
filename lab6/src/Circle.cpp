#define _USE_MATH_DEFINES
#include <cmath>

#include "Circle.hpp"

Circle::Circle() : Shape(50 + 2),
                   center(sf::Vector2f(200, 200)),
                   radius(50)
{
    this->points.setPrimitiveType(sf::TriangleFan);

    double pi = M_PI;
    double step = 1. / this->num - 2;
    this->points[0].position = center;
    for (int i = 1; i < this->num - 1; i++)
    {
        double angle = (i - 1) * step * (2 * pi);

        this->points[i] = sf::Vector2f(center.x + radius * cos(angle), center.y + radius * sin(angle));
    }
    this->points[this->num - 1].position = sf::Vector2f(center.x + radius * cos(0), center.y + radius * sin(0));
}

Circle::Circle(unsigned countOfPoints, unsigned radius, const sf::Vector2f &center) : Shape(countOfPoints + 2),
                                                                                      center(center),
                                                                                      radius(radius)
{
    this->points.setPrimitiveType(sf::TriangleFan);

    double pi = M_PI;
    double step = 1. / countOfPoints;
    this->points[0].position = center;
    for (int i = 1; i < this->num - 1; i++)
    {
        double angle = (i - 1) * step * (2 * pi);

        this->points[i] = sf::Vector2f(center.x + radius * cos(angle), center.y + radius * sin(angle));
    }
    this->points[this->num - 1].position = sf::Vector2f(center.x + radius * cos(0), center.y + radius * sin(0));
}