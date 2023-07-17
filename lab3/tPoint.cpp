#include "tPoint.hpp"

tPoint::tPoint(double x, double y) : x(x), y(y) 
{
    point.setRadius(5);
    point.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
    point.setPosition(rand()%width, rand()%height);

    dx = 0.05*((rand()%3) - 1);
    dy = 0.05*((rand()%3) - 1);
}

double tPoint::getX() const
{
    return x;
}

void tPoint::setX(double x)
{
    this->x = x;
}

double tPoint::getY() const
{
    return y;
}

void tPoint::setY(double y) 
{
    this->y = y;
}

void tPoint::move(double xx, double yy)
{
    setX(x + xx);
    setY(y + yy);
    point.setPosition(this->x, this->y);
}

void tPoint::move(double time)
{
    setX(x + dx*time);
    setY(y + dy*time);
    point.setPosition(this->x, this->y);
}

void tPoint::setPosition(double x, double y)
{
    setX(x);
    setY(y);
    point.setPosition(this->x, this->y);
}

double tPoint::getDx()
{
    return this->dx;
}

double tPoint::getDy()
{
    return this->dy;
}

void tPoint::setDx(double dx)
{
    this->dx = dx;
}

void tPoint::setDy(double dy)
{
    this->dy = dy;
}

sf::CircleShape& tPoint::getPoint()
{
    return this->point;
}