#include "figures.hpp"


///////////////
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

sf::Vector2f  Shape::getMoveDerection() const
{
    return this->moveDerection;
}

int           Shape::getWindowHeight() const
{
    return this->windowHeight;
}

int           Shape::getWindowWidth() const
{
    return this->windowWidth;
}

void          Shape::setMoveDerection(sf::Vector2f  moveDerection)
{
    this->moveDerection = moveDerection;
}

sf::Color     Shape::getColor() const
{
    return this->color;
}

void          Shape::setColor(sf::Color color)
{
    this->color = color;
}


//////////////
// class Point
//////////////

Point::Point(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius) : Shape(moveDerection, color, width, height)
{
    this->radius = radius;
    this->position = position;
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
}

Point::Point(int windowWidth, int windowHeight, int radius) : Shape(windowWidth, windowHeight)
{
    this->position = sf::Vector2f(rand()%1280, rand()%720);
    this->radius = radius;
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
}

sf::Vector2f  Point::getPosition() const
{
    return this->position;
}

void          Point::setPosition(sf::Vector2f position)
{
    this->position = position;
}

void          Point::setPosition(float x, float y)
{
    this->position = sf::Vector2f(x, y);
}

void          Point::setPoint(sf::Vector2f pos)
{
    this->point.setPosition(pos);
}

void          Point::move(float speed)
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
    
    if (newPos.x > width || newPos.x < 0)
    {
        newPos = pos;
        mvDer.x = mvDer.x * -1; 
        this->setMoveDerection(mvDer);
    }
    else if (newPos.y > height || newPos.y < 0)
    {
        newPos = pos;
        mvDer.y = mvDer.y * -1; 
        this->setMoveDerection(mvDer);
    }

    this->setPosition(newPos);
    this->setPoint(newPos);
}

sf::CircleShape Point::getPoint()
{
    return this->point;
}


////////////////
//  class Circle
////////////////


Circle::Circle(sf::Vector2f position, sf::Vector2f moveDerection, sf::Color color, int width, int height, int radius) : Shape(moveDerection, color, width, height)
{
    this->radius = radius;
    this->position = position;
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
}

Circle::Circle(int radius, int windowWidth, int windowHeight ) : Shape(windowWidth, windowHeight)
{
    this->radius = radius;
    this->position = sf::Vector2f(this->radius+(rand()%(1280 - this->radius)), this->radius+(rand()%(720 - this->radius)));
    point.setRadius(radius);
    point.setOrigin(radius, radius);
    point.setPosition(this->position);
}

sf::Vector2f  Circle::getPosition() const
{
    return this->position;
}

void          Circle::setPosition(sf::Vector2f position)
{
    this->position = position;
}

void          Circle::setPosition(float x, float y)
{
    this->position = sf::Vector2f(x, y);
}

void          Circle::setPoint(sf::Vector2f pos)
{
    this->point.setPosition(pos);
}

void          Circle::move(float speed)
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
        newPos = pos;
        mvDer.x = mvDer.x * -1; 
        this->setMoveDerection(mvDer);
    }
    else if (newPos.y > height - this->radius || newPos.y < this->radius)
    {
        newPos = pos;
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

void            Circle::rotate(float angle)
{
    this->point.rotate(angle);
}