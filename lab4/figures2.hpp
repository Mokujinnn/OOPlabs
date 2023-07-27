#pragma once
#include <SFML/Graphics.hpp>

class Point
{
private:
    sf::Vector2f  position;

public:
    float         getX() const;
    void          setX(float x);
    float         getY() const;
    void          setY(float y);
    sf::Vector2f  getPosition() const;
    void          setPosition(sf::Vector2f pos);
    void          setPosition(float x, float y);

};

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

class Circle : public Shape
{
private:
    sf::Vector2f     position;
    sf::CircleShape  point;
    int              radius;

public:
    Circle(int radius = 100, int windowWidth = 1280, int windowHeight = 720);
    Circle(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius = 100);
    sf::Vector2f     getPosition() const;
    void             setPosition(sf::Vector2f position);
    void             setPosition(float x, float y);
    void             move(float speed);
    sf::CircleShape  getPoint();
    void             setPoint(sf::Vector2f pos);
    void             rotate(float degre);
    void             draw(sf::RenderWindow& window);
    void             setRadius(int r);
    int              getRadius() const;

};

class Line : public Shape
{
private:
    sf::VertexArray vertex;

public:
    Line(sf::Vector2f p1, sf::Vector2f p2, int windowWidth = 1280, int windowHeight = 720);
    void             setVertex(sf::VertexArray vertex);
    sf::VertexArray  getVertex() const;
    void             rotate(float degre);
    void             draw(sf::RenderWindow& window);
    void             move(float speed);
};

class Rectangle : public Shape
{
private:
    Point              points[4];
    sf::Vector2f       size;
    sf::RectangleShape rectangle;
    
public:
    Rectangle(sf::Vector2f size = sf::Vector2f(100, 100), int windowWidth = 1280, int windowHeight = 720);
    Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Vector2f moveDerection, sf::Color color, int width, int height);

    sf::Vector2f       getPosition() const;
    void               setPosition(sf::Vector2f position);
    void               setPosition(float x, float y);
    void               setRect(sf::Vector2f pos);
    sf::RectangleShape getRect();
    void               move(float speed);
    void               rotate(float degre);
    void               draw(sf::RenderWindow& window);
};