#include "Zombie.h"



bool Zombie::isAlive(){
    return alive;
}

Sprite Zombie::getSprite(){
    return sprite;
}

void Zombie::hit(){
    alive=false;
}

void Zombie::spawn(Vector2f position){
    
}
