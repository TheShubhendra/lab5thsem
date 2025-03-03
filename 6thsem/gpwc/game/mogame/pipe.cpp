#include "pipe.hpp"

#define WIDTH 1366
#define HEIGHT 768



std::vector<Pipe*> Pipe::pipes;
double Pipe::spawnElapsed;
sf::Clock Pipe::spawnClock;
int Pipe::score;
float Pipe::speed = 0.35;
float Pipe::acceleration = 0.04;
int Pipe::gap = 200;

sf::Sprite coin;
sf::Texture coin_t;
Pipe::Pipe(){
    this->clock = sf::Clock();
    int upper_height = (std::rand()%400)+100;
    upper_height = (upper_height % 400) + 100;

    int lower_height = HEIGHT-upper_height-gap;
    const int width = 32;
    texture.loadFromFile("assets/tile.png");
    texture.setRepeated(true);

    this->upper.setTexture(texture);
    this->lower.setTexture(texture);

    
    this->upper.setTextureRect({0, 0, width, upper_height});
    this->lower.setTextureRect({0, 0, width, lower_height});

    this->upper.setPosition(sf::Vector2f(WIDTH-width, 0));
    this->lower.setPosition(sf::Vector2f(WIDTH-width, HEIGHT-lower_height));

}

void Pipe::draw(sf::RenderWindow* window){
    window->draw(this->lower);
    window->draw(this->upper);
}

void Pipe::move(){
    sf::Time time = Pipe::clock.restart();
    this->upper.setPosition(sf::Vector2f(this->upper.getPosition().x - speed*time.asMilliseconds(), this->upper.getPosition().y));
    this->lower.setPosition(sf::Vector2f(this->lower.getPosition().x - speed*time.asMilliseconds(), this->lower.getPosition().y));
}

bool Pipe::isColliding(sf::FloatRect bounds){
    return this->upper.getGlobalBounds().intersects(bounds) || this->lower.getGlobalBounds().intersects(bounds);
}

bool Pipe::isOut(){
    return this->upper.getPosition().x <-50;
}

void Pipe::drawAll(sf::RenderWindow* window){
    // window->draw(coin);
    for (int i = 0; i < pipes.size(); i++){
        pipes[i]->draw(window);
        pipes[i]->move();
        if (pipes[i]->isOut()){
            pipes.erase(pipes.begin() + i);
        }
        if (!pipes[i]->passed && pipes[i]->upper.getPosition().x<70){
            score++;
            pipes[i]->passed = true;
            speed+=acceleration;
            gap-=5;
        }
    }


    spawnElapsed += spawnClock.restart().asSeconds();
    if(spawnElapsed >= 0.8/speed){
        spawnElapsed = 0.0;
        Pipe::addPipe();
    }


}

void Pipe::addPipe(){
    pipes.push_back(new Pipe());
}