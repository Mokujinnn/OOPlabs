#pragma once
#include <SFML/Graphics.hpp>

// #define width 1280
// #define height 720


class Shape
{
private:
    sf::Vector2f  moveDerection;
    sf::Color     color;
    int           windowHeight;
    int           windowWidth;

    void          createShape(sf::Vector2f moveDerection, sf::Color color, int width, int height);


public:

    Shape(int windowWidth = 1280, int windowHeight = 720);

    Shape(sf::Vector2f moveDerection, sf::Color color, int width , int height);

    int           getWindowHeight() const;

    int           getWindowWidth() const;

    sf::Vector2f  getMoveDerection() const;

    void          setMoveDerection(sf::Vector2f  moveDerection);

    sf::Color     getColor() const;

    void          setColor(sf::Color color);

};

class Point : public Shape
{
private:
    sf::Vector2f     position;
    sf::CircleShape  point;
    int              radius;

public:
    Point(int radius = 5, int windowWidth = 1280, int windowHeight = 720);

    Point(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius = 5);

    sf::Vector2f     getPosition() const;

    void             setPosition(sf::Vector2f position);

    void             setPosition(float x, float y);

    void             move(float speed);

    sf::CircleShape  getPoint();

    void             setPoint(sf::Vector2f pos);
};


class Circle : public Shape
{
private:
    sf::Vector2f     position;
    sf::CircleShape  point;
    int              radius;

public:

    Circle(int radius = 100, int windowWidth = 1280, int windowHeight = 720 );

    Circle(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius = 5);

    sf::Vector2f     getPosition() const;

    void             setPosition(sf::Vector2f position);

    void             setPosition(float x, float y);

    void             move(float speed);

    sf::CircleShape  getPoint();

    void             setPoint(sf::Vector2f pos);

    void             rotate(float degre);
};