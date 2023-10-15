#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "myshape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Rhomb.hpp"
#include "Ellipse.hpp"

int main()
{
    srand(time(NULL));

    int windowWidth = 1280;
    int windowHeight = 720;

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Test");
    window.setPosition(sf::Vector2i(300, 150));

    float speedFactor = 2;

    Point p(windowWidth, windowHeight);
    Line line(sf::Vector2f(100, 100), sf::Vector2f(200, 300));
    Circle circ(100, 80, sf::Vector2f(200, 200));
    Triangle tr(sf::Vector2f(300, 300), sf::Vector2f(200, 67), sf::Vector2f(350, 222));
    Rectangle rect(sf::Vector2f(600, 600), sf::Vector2f(750, 700));
    Rhomb rh(sf::Vector2f(300, 300), 100, 50);
    Ellipse el(100, sf::Vector2f(400, 400), 130, 70);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();

        float speed = time * speedFactor;

        // std::cout << time << '\n';

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        p.move(speed, windowWidth, windowHeight);
        line.move(speed, windowWidth, windowHeight);
        circ.move(speed, windowWidth, windowHeight);
        tr.move(speed, windowWidth, windowHeight);
        rect.move(speed, windowWidth, windowHeight);
        rh.move(speed, windowWidth, windowHeight);
        el.move(speed, windowWidth, windowHeight);

        window.clear();

        p.draw(window);
        line.draw(window);
        circ.draw(window);
        tr.draw(window);
        rect.draw(window);
        rh.draw(window);
        el.draw(window);

        window.display();
    }

    return 0;
}