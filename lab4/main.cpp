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
    
    Rectangle rect;

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

        rect.move(time*0.2);
        rect.rotate(0.2);

        //std::cout << rect.getPosition().x << ' ' << rect.getPosition().y << '\n';

        window.clear();
        rect.draw(window);
        window.display();
    }

    return 0;
}