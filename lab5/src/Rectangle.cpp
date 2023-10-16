#include "Rectangle.hpp"

Rectangle::Rectangle(const sf::Vector2f &p1, const sf::Vector2f &p2) : Shape(4)
{
    this->points.setPrimitiveType(sf::Quads);

    this->points[0].position = p1;
    this->points[1].position = sf::Vector2f(p2.x, p1.y);
    this->points[2].position = p2;
    this->points[3].position = sf::Vector2f(p1.x, p2.y);
}

void Rectangle::rotate(float angle, unsigned width, unsigned height)
{
    sf::Vector2f center = this->points[0].position + this->points[2].position;
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