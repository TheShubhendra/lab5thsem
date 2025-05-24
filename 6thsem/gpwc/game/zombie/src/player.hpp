#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

enum class Direction{
    LEFT, RIGHT, UP, DOWN
};

class Player{
    
    private:
        const float START_SPEED = 2000;
        const float START_HEALTH = 100;


        int health;
        int maxHealth;
        float speed;
        Sprite sprite;
        Texture texture;
        Vector2f resolution;

        Direction direction;
        bool isMoving;

        Clock clock;

    public:
        Player();

        Vector2f getPosition();
        Vector2f getCenter();
        Sprite getSprite();
        void spawn(IntRect arena, Vector2f resolution, int tileSize);
        void startMove(Direction);
        void stopMove();

        void move(float);
        void update(float, Vector2i);
};