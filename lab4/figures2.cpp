#include "figures2.hpp"
#include <cmath>

// class Point

float Point::getX() const
{
    return this->getPosition().x;
}

void Point::setX(float x)
{
  this->position.x = x;
}

float Point::getY() const
{
    return this->getPosition().y;
}

void Point::setY(float y)
{
    this->position.y = y;
}

sf::Vector2f Point::getPosition() const
{
    return this->position;
}

void Point::setPosition(sf::Vector2f pos)
{
    this->position = pos;
}

void Point::setPosition(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}

//  class Shape 
///////////////
void Shape::createShape(sf::Vector2f moveDerection, sf::Color color, int width , int height)
{
    this->moveDerection = moveDerection;
    this->color         = color;
    this->windowHeight  = height;
    this->windowWidth   = width;
}

Shape::Shape(int windowWidth, int windowHeight)
{
    createShape(sf::Vector2f(rand()%3 - 1, rand()%3 - 1), sf::Color::Green, windowWidth, windowHeight);
}

Shape::Shape(sf::Vector2f moveDerection, sf::Color color, int width = 1280, int height = 720)
{
    createShape(moveDerection, color, windowWidth, windowHeight);
}

sf::Vector2f Shape::getMoveDerection() const
{
    return this->moveDerection;
}

int Shape::getWindowHeight() const
{
    return this->windowHeight;
}

int Shape::getWindowWidth() const
{
    return this->windowWidth;
}

void Shape::setMoveDerection(sf::Vector2f  moveDerection)
{
    this->moveDerection = moveDerection;
}

sf::Color Shape::getColor() const
{
    return this->color;
}

void Shape::setColor(sf::Color color)
{
    this->color = color;
}

//  class Circle
////////////////

Circle::Circle(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius) : Shape(moveDerection, color, width, height)
{
    this->radius = radius;
    this->position = position;
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
    point.setFillColor(this->getColor());
}

Circle::Circle(int radius, int windowWidth, int windowHeight ) : Shape(windowWidth, windowHeight)
{
    this->radius = radius;
    this->position = sf::Vector2f(this->radius+(rand()%(1280 - 2 * this->radius)), this->radius+(rand()%(720 - 2 * this->radius)));
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
    point.setFillColor(this->getColor());
}

sf::Vector2f Circle::getPosition() const
{
    return this->position;
}

void Circle::setPosition(sf::Vector2f position)
{
    this->position = position;
}

void Circle::setPosition(float x, float y)
{
    this->position = sf::Vector2f(x, y);
}

void Circle::setPoint(sf::Vector2f pos)
{
    this->point.setPosition(pos);
}

void Circle::move(float speed)
{
    sf::Vector2f pos    = this->getPosition();
    sf::Vector2f mvDer  = this->getMoveDerection();
    float x             = pos.x;
    float y             = pos.y;
    float dx            = mvDer.x;
    float dy            = mvDer.y;
    sf::Vector2f newPos(x + dx * speed, y + dy * speed);

    int width  = this->getWindowWidth();
    int height = this->getWindowHeight();
    
    if (newPos.x > width - this->radius || newPos.x  < this->radius)
    {
        newPos  = pos;
        mvDer.x = mvDer.x * -1; 
        this->setMoveDerection(mvDer);
    }
    if (newPos.y > height - this->radius || newPos.y < this->radius)
    {
        newPos  = pos;
        mvDer.y = mvDer.y * -1; 
        this->setMoveDerection(mvDer);
    }

    this->setPosition(newPos);
    this->setPoint(newPos);
}

sf::CircleShape Circle::getPoint()
{
    return this->point;
}

void Circle::rotate(float angle)
{
    this->point.rotate(angle);
}

void Circle::draw(sf::RenderWindow& window)
{
    window.draw(this->point);
}

void Circle::setRadius(int r)
{
    this->radius = r;
}

int Circle::getRadius() const
{
    return this->radius;
}

// class Line

Line::Line(sf::Vector2f p1, sf::Vector2f p2, int windowWidth, int windowHeight) : Shape(windowWidth, windowHeight)
{
    this->vertex = sf::VertexArray(sf::Lines, 2);
    this->vertex[0].position = p1;
    this->vertex[1].position = p2;
    this->vertex[0].color = this->getColor();
    this->vertex[1].color = this->getColor();
}

void Line::setVertex(sf::VertexArray v)
{
    this->vertex = v;
}

sf::VertexArray Line::getVertex() const
{
    return this->vertex;
}

void Line::draw(sf::RenderWindow& window)
{
    window.draw(this->vertex);
}

void Line::rotate(float angle)
{
    float x1, y1, x2, y2;
    x1 = this->vertex[0].position.x;
    y1 = this->vertex[0].position.y;
    x2 = this->vertex[1].position.x;
    y2 = this->vertex[1].position.y;

    x1 = x1 * cos(angle) + y1 * sin(angle);
    y1 = y1 * cos(angle) - x1 * sin(angle);

    //x2 = x2 * cos(angle) - y2 * sin(angle);
   // y2 = y2 * cos(angle) + x2 * sin(angle);

    this->vertex[0].position.x = x1;
    this->vertex[0].position.y = y1;
    this->vertex[1].position.x = x2;
    this->vertex[1].position.y = y2;
}