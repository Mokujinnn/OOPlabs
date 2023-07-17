#pragma once
#include <SFML/Graphics.hpp>

#define width 1280
#define height 720

class tPoint
{
public:

    tPoint(double x = rand()%width, double y = rand()%height);

    double getX() const;

    void setX(double x);
 
    double getY() const;

    void setY(double y) ;

    void move(double xx, double yy);

    void move(double time);

    void setPosition(double xx, double yy);

    double getDx();

    double getDy();

    void setDx(double dx);

    void setDy(double dy);

    sf::CircleShape& getPoint();


private:
    double x;
    double y;
    double dx;
    double dy;

    sf::CircleShape point;
};