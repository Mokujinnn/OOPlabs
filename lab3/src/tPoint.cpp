#include "tPoint.hpp"
#include <cmath>

tPoint::tPoint()
{
    point.position = sf::Vector2f(100, 100);
    point.color = sf::Color(rand()%256, rand()%256, rand()%256);

    velocity = sf::Vector2f(0, 0);
}

void tPoint::setPosition(sf::Vector2f p)
{
    point.position = p;
}

sf::Vector2f tPoint::getPosition()
{
    return this->point.position;
}

void tPoint::setVelocity(sf::Vector2f v)
{
    velocity = v;
}

sf::Vector2f tPoint::getVelocity()
{
    return this->velocity;
}

void tPoint::setColor(sf::Color cl)
{
    point.color = cl;
}

sf::Color tPoint::getColor()
{
    return point.color;
}

void tPoint::move(float speed, unsigned width, unsigned height)
{
    sf::Vector2f newPos = sf::Vector2f(point.position.x + (speed * velocity.x), point.position.y + (speed * velocity.y));

    if(newPos.x > width || newPos.x < 0)
    {
        newPos.x = point.position.x;
        velocity.x *= -1;
    }
    else if(newPos.y > height || newPos.y < 0)
    {
        newPos.y = point.position.y;
        velocity.y *= -1;
    }

    point.position = newPos;
}

void tPoint::draw(sf::RenderWindow& window)
{
    window.draw(&point, 1, sf::Points);
}

void tPoint::randomRotate(float minAngle, float maxAngle)
{
    float angle = (float)(rand())/RAND_MAX*(maxAngle - minAngle) + minAngle;

    sf::Vector2f v = velocity;

    v.x = velocity.x * cos(angle) - velocity.y * sin(angle);
    v.y = velocity.y * cos(angle) + velocity.x * sin(angle);

    velocity = v;
}

void tPoint::moveRand(float speed, float chanceToRotate, unsigned width, unsigned height)
{
    float i = rand()%10000 * 0.0001;

    if(i < chanceToRotate)
        randomRotate(-1,1);

    move(speed, width, height);
}