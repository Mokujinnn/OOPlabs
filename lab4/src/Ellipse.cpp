#include "Ellipse.hpp"

#include <vector>
#include <cmath>

Ellipse::Ellipse(unsigned countOfPoints, const sf::Vector2f &center, float a, float b) : Shape(countOfPoints + 2)
{
    this->points.setPrimitiveType(sf::TriangleFan);

    double c = sqrt(pow(a, 2) - pow(b, 2));

    this->f1 = sf::Vector2f(center.x + c, center.y);
    this->f2 = sf::Vector2f(center.x - c, center.y);

    double inc = (4 * a) / countOfPoints;

    this->points[0].position = center;
    int i = 1;
    for (double x = -a; x <= a; x += inc)
    {
        double y = (1 / a) * sqrt(pow(b, 2) * (pow(a, 2) - pow(x, 2)));
        this->points[i].position = sf::Vector2f(center.x + x, center.y + y);
        i++;
    }
    for (double x = a - inc; x >= -a; x -= inc)
    {
        double y = (1 / a) * sqrt(pow(b, 2) * (pow(a, 2) - pow(x, 2)));
        this->points[i].position = sf::Vector2f(center.x + x, center.y - y);
        i++;
    }
}
