#pragma once
#include <SFML/Graphics.hpp>

#define width 1280
#define height 720


class Shape
{
private:
    double x;
    double y;
    double dx;
    double dy;

public:
    Shape(double x = rand()%width, double y = rand()%height);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    void move(double x, double y);

    void move(double time);

    void setPosition(double x, double y);

    double getDx();

    double getDy();

    void setDx(double dx);
    
    void setDy(double dy);

}