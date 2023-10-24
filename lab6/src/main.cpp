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
    float t = 0;

    // Point p(windowWidth, windowHeight);
    // Line lines[3];

    // Circle circls[2];

    // Triangle tr(sf::Vector2f(300, 300), sf::Vector2f(200, 67), sf::Vector2f(350, 222));
    // Rectangle rect(sf::Vector2f(600, 600), sf::Vector2f(750, 700));
    // Rhomb rh(sf::Vector2f(300, 300), 150, 70);
    // Ellipse el(100, sf::Vector2f(400, 400), 130, 80);

    Shape **shapes = new Shape *[10];

    shapes[0] = new Point(windowWidth, windowHeight);
    shapes[1] = new Line;
    shapes[2] = new Line;
    shapes[3] = new Line;
    shapes[4] = new Circle;
    shapes[5] = new Circle(50, 100, sf::Vector2f(300, 300));
    shapes[6] = new Triangle(sf::Vector2f(300, 300), sf::Vector2f(200, 67), sf::Vector2f(350, 222));
    shapes[7] = new Rectangle(sf::Vector2f(600, 600), sf::Vector2f(750, 700));
    shapes[8] = new Rhomb(sf::Vector2f(300, 300), 150, 70);
    shapes[9] = new Ellipse(100, sf::Vector2f(400, 400), 130, 80);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();

        t += time;

        float speed = time * speedFactor;

        // std::cout << time << '\n';

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                for (int i = 0; i < 10; i++)
                {
                    delete shapes[i];
                }
                delete[] shapes;

                window.close();
            }
        }

        bool flag = true;
        for (int i = 0; i < 10; i++)
        {
            shapes[i]->move(speed, windowWidth, windowHeight);

            if (t >= 2)
            {
                shapes[i]->rotate();
                flag = false;
            }
        }

        if (!flag)
        {
            t -= 2;
        }

        window.clear();

        for (int i = 0; i < 10; i++)
        {
            shapes[i]->draw(window);
        }

        window.display();
    }

    return 0;
}