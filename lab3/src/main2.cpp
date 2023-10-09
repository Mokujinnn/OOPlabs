#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "tPoint.hpp"


int main()
{
    srand(time(NULL));

    int windowWidth = 1280;
    int windowHeight = 720;

    int n = 100;
    
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Test");
    window.setPosition(sf::Vector2i(100, 50));
    window.setVerticalSyncEnabled(true);
    
    tPoint *points = new tPoint[n];
    for(int i = 0; i < n; i++)
    {
        points[i].setPosition(sf::Vector2f(rand()%windowWidth, rand()%windowHeight));
        points[i].setVelocity(sf::Vector2f((rand()%200 - n) * 0.01, (rand()%200 - n) * 0.01));
    }

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                delete [] points;
                window.close();
            }
        }

        for(int i = 0; i < n; i++)
        {
            points[i].moveRand(time*0.05, 0.02, windowWidth, windowHeight);
        }

        window.clear();
        for(int i = 0; i < n; i++)
        {
            points[i].draw(window);
        }

        window.display();
    }

    return 0;
}