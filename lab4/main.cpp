#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "figures.hpp"

int main()
{
    srand(time(NULL));

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");
    window.setPosition(sf::Vector2i(300, 150));
    window.setVerticalSyncEnabled(true);
    
    Rect rect;


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

        rect.rotate(0.1);
        rect.move(time* 0.25);

        window.clear();
        rect.draw(window);
        window.display();

    }

    return 0;
}