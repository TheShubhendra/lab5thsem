#include "player.hpp"



Player::Player(){
    this->texture.loadFromFile("graphics/player.png");
    this->sprite.setTexture(this->texture);
    this->speed = 20;
}

Vector2f Player::getPosition(){
    return this->sprite.getPosition();
}

Vector2f Player::getCenter(){
    return Vector2f(
        this->sprite.getGlobalBounds().left/2 + this->sprite.getGlobalBounds().width/2,
        this->sprite.getGlobalBounds().top/2 + this->sprite.getGlobalBounds().height/2
    );
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

void Player::update(float secondsElapsed, Vector2i moursePosition){
    if(isMoving){
        this->move(secondsElapsed);
    }

}

void Player::startMove(Diretion direction){
    this->direction = direction;
    
}