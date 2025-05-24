#pragma once
#include<SFML/Graphics.hpp>

enum Direction{
    LEFT,
    RIGHT
};

class Bat{
  public:
   sf::RectangleShape sprite = sf::RectangleShape();

   Bat(sf::Vector2f, sf::Vector2f);

   void move(Direction direction);

  private:
    static float speed;

};