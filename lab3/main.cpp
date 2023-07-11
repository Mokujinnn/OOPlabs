#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>


#define width 1280
#define height 720

class tPoint
{
public:

    tPoint(double x = rand()%width, double y = rand()%height) : x(x), y(y) 
    {
        point.setRadius(5);
        point.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255));
        point.setPosition(rand()%width, rand()%height);

        dx = 0.05*((rand()%3) - 1);
        dy = 0.05*((rand()%3) - 1);
    }

    double getX() const
    {
        return x;
    }

    void setX(double x)
    {
        this->x = x;
    }

    double getY() const
    {
        return y;
    }

    void setY(double y) 
    {
        this->y = y;
    }

    void move(double xx, double yy)
    {
        setX(x + xx);
        setY(y + yy);
        point.setPosition(this->x, this->y);
    }

    void move(double time)
    {
        setX(x + dx*time);
        setY(y + dy*time);
        point.setPosition(this->x, this->y);
    }

    void setPosition(double xx, double yy)
    {
        setX(xx);
        setY(yy);
        point.setPosition(this->x, this->y);
    }

    sf::CircleShape& getPoint()
    {
        return point;
    }

private:
    double x;
    double y;
    double dx;
    double dy;

    sf::CircleShape point;
};

int main()
{
    srand(time(NULL));
    tPoint points[100];

    sf::RenderWindow window(sf::VideoMode(width, height), "Test");
    window.setPosition(sf::Vector2i(100, 50));

    sf::Clock clock;

    

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i = 0; i < 100; i++)
        {
            points[i].move(time);
        }



        window.clear();
        for (int i = 0; i < 100; i++)
        {
            window.draw(points[i].getPoint());
        }
        window.display();
    }

    return 0;
}