#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "figures2.hpp"

int main()
{
    srand(time(NULL));

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");
    window.setPosition(sf::Vector2i(300, 150));
    window.setVerticalSyncEnabled(true);
    
    Line line(sf::Vector2f(600, 300), sf::Vector2f(400, 500));


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

        line.rotate(0.01);
        line.move(time* 0.25);

        window.clear();
        line.draw(window);
        window.display();

    }

    return 0;
}