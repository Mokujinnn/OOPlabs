#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "tPoint.hpp"


int main()
{
    srand(time(NULL));
    tPoint points[100];

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(width, height), "Test");
    window.setPosition(sf::Vector2i(100, 50));
    window.setVerticalSyncEnabled(true);


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
            double x = points[i].getX();
            double y = points[i].getY();

            if (x <= 0) 
            {
                points[i].setDx(points[i].getDx() * -1);
                points[i].setPosition(0, points[i].getY());
            }
            if (x >= width) 
            {
                points[i].setDx(points[i].getDx() * -1);
                points[i].setPosition(width, points[i].getY());
            }
            if (y <= 0) 
            {
                points[i].setDy(points[i].getDy() * -1);
                points[i].setPosition(points[i].getX(), 0);
            }
            if (y >= height) 
            {
                points[i].setDy(points[i].getDy() * -1);
                points[i].setPosition(points[i].getX(), height);
            }

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