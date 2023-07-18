#include "figures.hpp"

Shape::Shape(double x, double y)
{
   this->x = x;
   this->y = y;
}

Shape::Shape()
{
    this->x = rand()%width;
    this->y = rand()%height;
}

double Shape::getX() const
{
    return x;
}

void Shape::setX(double x)
{
    this->x = x;
}

double Shape::getY() const
{
    return y;
}

void Shape::setY(double y) 
{
    this->y = y;

}

double Shape::getDx()
{
    return this->dx;
}

double Shape::getDy()
{
    return this->dy;
}

void Shape::setDx(double dx)
{
    this->dx = dx;
}

void Shape::setDy(double dy)
{
    this->dy = dy;

}


// Point::Point(double x, double y) : Shape(x, y)
// {
//     point.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
//     point.setPosition(this->x, this->y);
// }
