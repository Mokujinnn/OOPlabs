#pragma once
#include <SFML/Graphics.hpp>


class tPoint
{
private:

    sf::Vertex point;
    sf::Vector2f velocity;

    void randomRotate(float minAngle, float maxAngle);

public:

    tPoint();

    void setPosition(sf::Vector2f p);

    sf::Vector2f getPosition();

    void setVelocity(sf::Vector2f v);

    sf::Vector2f getVelocity();

    void setColor(sf::Color cl);

    sf::Color getColor();

    void move(float speed, unsigned width, unsigned height);

    void moveRand(float speed, float chanceToRotate, unsigned width, unsigned height);

    void draw(sf::RenderWindow& window);
};