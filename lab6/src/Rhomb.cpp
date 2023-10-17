#include "Rhomb.hpp"

Rhomb::Rhomb(const sf::Vector2f &center, float d1, float d2) : Shape(4)
{
    this->points.setPrimitiveType(sf::Quads);

    this->points[0].position = sf::Vector2f(center.x, center.y + d1 / 2);
    this->points[1].position = sf::Vector2f(center.x + d2 / 2, center.y);
    this->points[2].position = sf::Vector2f(center.x, center.y - d1 / 2);
    this->points[3].position = sf::Vector2f(center.x - d2 / 2, center.y);
}

void Rhomb::rotate(float angle)
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