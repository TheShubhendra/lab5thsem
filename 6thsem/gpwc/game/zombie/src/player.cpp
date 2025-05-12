#include "player.hpp"
#include <math.h>


Player::Player(){
    this->texture.loadFromFile("graphics/player.png");
    this->sprite.setTexture(this->texture);
    this->speed = 200;
    resolution.x  = 1920;
    resolution.y = 1080;
    sprite.setPosition(1920/2, 1080/2);
    FloatRect rect = sprite.getLocalBounds();
    sprite.setOrigin(rect.left + rect.width/4, rect.height + rect.top/4);
}

Vector2f Player::getPosition(){
    return this->sprite.getPosition();
}

Vector2f Player::getCenter(){
    return sprite.getPosition();
}

Sprite Player::getSprite(){
    return this->sprite;
}

void Player::move(float time){


    float distance = speed*time;
    if(direction==Direction::LEFT){
        sprite.move(-1*distance,0);
    }
    if(direction==Direction::RIGHT){
        sprite.move(distance,0);
    }
    if(direction==Direction::UP){
        sprite.move(0,-1*distance);
    }
    if(direction==Direction::DOWN){
        sprite.move(0,distance);
    }
}

void Player::update(float secondsElapsed, Vector2i mousePosition){
    if(isMoving){
        this->move(secondsElapsed);
    }

    float angle = (atan2(mousePosition.y - resolution.y / 2,
        mousePosition.x - resolution.x / 2)
        * 180) / 3.141;

    sprite.setRotation(angle);

}

void Player::spawn(IntRect arena, Vector2f resolution, int tileSize){

}

void Player::startMove(Direction direction){
    this->direction = direction;
    isMoving = true;
    
}

void Player::stopMove(){
    isMoving = false;
}