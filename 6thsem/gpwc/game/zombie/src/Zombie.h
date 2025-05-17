#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

enum 

class Zombie
{
private:
    const float BLOATER_SPEED = 40;
    const float CHASER_SPEED = 80;
    const float CRAWLER_SPEED = 20;
    const float BLOATER_HEALTH = 5;
    const float CHASER_HEALTH = 1;
    const float CRAWLER_HEALTH = 3;
    const int MAX_VARRIANCE = 30;
    const int OFFSET = 101 - MAX_VARRIANCE;

    Vector2f position;
    Sprite sprite;
    float speed;
    float health;
    bool alive;


public:
    void hit();
    bool isAlive();
    FloatRect getPosition();
    Sprite getSprite();
    void update();
    void spawn(Vector2f position);


};