#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


class Pipe{
    RectangleShape upper, lower;
    public:
    Pipe(){
        int upper_height = 30;
        int lower_height = 20;
        this->upper = RectangleShape(sf::Vector2f(10, upper_height));
        this->lower = RectangleShape(sf::Vector2f(10, lower_height));
    }

    void draw(RenderWindow* window){
        window->draw(this->lower);
        window->draw(this->upper);
    }
};

int main()
{
    const unsigned int width = 1000;
    const unsigned int height = 500;
    sf::RenderWindow window(sf::VideoMode(width, height), "Timber land");
    sf::CircleShape shape(100.f);
    sf::RectangleShape floor(sf::Vector2f(width, 50.f));
    floor.setPosition(Vector2f(0,height-50));
    shape.setFillColor(sf::Color::Green);
    int direction = 1;
    Pipe p1 = Pipe();
    while (window.isOpen())
    {
        if (shape.getScale().x > 10 & direction > 0){
            direction = -1;
        }
        if (shape.getScale().x < 1 & direction < 0){
            direction = 1;
        }
        // shape.scale(1+0.001*direction, 1+0.001*direction);
        // cout << shape.getScale().x << " " << shape.getScale().y << endl;
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        window.clear();
        window.draw(shape);
        p1.draw(&window);
        window.display();
    }

    return 0;
}