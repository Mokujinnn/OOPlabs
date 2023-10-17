#include "Line.hpp"

Line::Line(const sf::Vector2f &p1, const sf::Vector2f &p2) : Shape(2)
{
    this->points.setPrimitiveType(sf::Lines);
    this->points[0].position = p1;
    this->points[1].position = p2;
}

void Line::rotate(float angle, unsigned width, unsigned height)
{
    sf::Vector2f center = this->points[0].position + this->points[1].position;
    center = sf::Vector2f(center.x / 2, center.y / 2);

    for (int i = 0; i < this->num; i++)
    {
        float x1 = this->points[i].position.x - center.x;
        float y1 = this->points[i].position.y - center.y;

        float x = x1 * cos(angle) - y1 * sin(angle);
        float y = y1 * cos(angle) + x1 * sin(angle);

        this->points[i].position = sf::Vector2f(x + center.x, y + center.y);
    }
}