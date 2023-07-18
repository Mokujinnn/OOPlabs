#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "figures.hpp"

int main()
{
    srand(time(NULL));

    //sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(width, height), "Test");
    window.setPosition(sf::Vector2i(100, 50));
    window.setVerticalSyncEnabled(true);
    sf::CircleShape shape(100);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        //float time = clock.getElapsedTime().asMilliseconds();
        //clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

    }

    return 0;
}