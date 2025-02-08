#ifndef PIPE_HPP
#define PIPE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Pipe{
    private:
        static float speed, acceleration;
        static int gap;
        sf::Sprite upper, lower;
        sf::Texture texture;
        sf::Clock clock;
        bool passed;
        static sf::Clock spawnClock;
        static double spawnElapsed;

    public:
        static int score;
        static std::vector<Pipe*> pipes;

        Pipe();
        void draw(sf::RenderWindow* window);
        void move();
        bool isOut();
        static void drawAll(sf::RenderWindow* window);
        static void addPipe();
        bool isColliding(sf::FloatRect bounds);

};

#endif