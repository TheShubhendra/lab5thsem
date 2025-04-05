#include "bat.hpp"

float Bat::speed = 10.5;

Bat::Bat(sf::Vector2f intialPosition , sf::Vector2f size){
    sprite.setPosition(intialPosition);
    sprite.setSize(size);
    
}

void Bat::move(Direction direction){
    sf::Vector2f currPosition = sprite.getPosition();

    if (direction == Direction::LEFT && currPosition.x>0){
        sprite.setPosition(currPosition.x-speed, currPosition.y);
    }
    if (direction == Direction::RIGHT && currPosition.x + sprite.getGlobalBounds().width < 1920){
        sprite.setPosition(currPosition.x+speed, currPosition.y);
    }
}
