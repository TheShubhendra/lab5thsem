#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>
#include <unistd.h>


#define WIDTH 1366
#define HEIGHT 768
#define PIPE_MOVEMENT_SPEED 0.05


using namespace std;
using namespace sf;




class Pipe{
    const float speed = 0.3;
    RectangleShape upper, lower;
    Clock clock;
    public:
    Pipe(){
        this->clock = Clock();
        const int gap = 120;
        int upper_height = (std::rand()%400)+100;
        upper_height = (upper_height % 400) + 100;

        int lower_height = HEIGHT-upper_height-gap;
        const int width = 20;
        this->upper = RectangleShape(sf::Vector2f(width, upper_height));
        this->lower = RectangleShape(sf::Vector2f(width, lower_height));
        this->upper.setPosition(Vector2f(WIDTH-width, 0));
        this->lower.setPosition(Vector2f(WIDTH-width, HEIGHT-lower_height));

        this->upper.setFillColor(Color::Black);
        this->lower.setFillColor(Color::Black);
    }

    void draw(RenderWindow* window){
        window->draw(this->lower);
        window->draw(this->upper);
    }

    void move(){
        Time time = clock.restart();
        this->upper.setPosition(Vector2f(this->upper.getPosition().x - speed*time.asMilliseconds(), this->upper.getPosition().y));
        this->lower.setPosition(Vector2f(this->lower.getPosition().x - speed*time.asMilliseconds(), this->lower.getPosition().y));
    }

    bool isColliding(FloatRect bounds){
        return this->upper.getGlobalBounds().intersects(bounds) || this->lower.getGlobalBounds().intersects(bounds);
    }
};


class Character{


    Texture texture1, texture2, texture3;

    public:
    Sprite sprite;
    Character(){
        texture1.loadFromFile("assets/character/idle/frame-1.png");
        texture2.loadFromFile("assets/character/idle/frame-2.png");
        texture3.loadFromFile("assets/character/got hit/frame-2.png");
        sprite.setTexture(texture1);
        sprite.scale(Vector2f(.1,.1));
        sprite.setPosition(Vector2f(70, HEIGHT/2));

    }

    void draw(RenderWindow* window){
        if (Keyboard::isKeyPressed(Keyboard::Up)){
            sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y - 0.2));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)){
            sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y + 0.2));
        }
        window->draw(this->sprite);
    }

    bool checkColision(std::vector<Pipe*> pipes){
        for (int i = 0; i < pipes.size(); i++){
            if (pipes[i]->isColliding(sprite.getGlobalBounds())){
                sprite.setTexture(texture3);
            
                
                return true;
            }
        }
        return false;
    }

    void mouseScroll(int delta){
        sprite.setPosition(Vector2f(sprite.getPosition().x, sprite.getPosition().y - 20*delta));
    }
};


int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mo game");

    Clock pipeSpawnClock;



    Texture textureBackground; 
    Sprite spriteBackground;
    Font font;
    font.loadFromFile("assets/HennyPenny-Regular.ttf");

    Text scoreBoard;

    scoreBoard.setFont(font);
    scoreBoard.setString("Score: 0");
    scoreBoard.setFillColor(Color::Black);
    scoreBoard.setPosition(Vector2f(10, 10));



    textureBackground.loadFromFile("assets/background.png"); 
    
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    spriteBackground.scale(Vector2f(WIDTH/textureBackground.getSize().x,HEIGHT/textureBackground.getSize().y));


    Pipe pipe = Pipe();
    Character character = Character();
    std::vector<Pipe*> pipes;
    pipes.push_back(&pipe);
    Time pipeSpawnElapsed = pipeSpawnClock.restart();
    double spawnElapsed = 0;
    sf::Event event;
    int score=0;
    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();
        window.draw(spriteBackground);
        scoreBoard.setString("Score: "+to_string(score));
        window.draw(scoreBoard);
        character.draw(&window);
        

        for (Pipe* pipe: pipes){
            (*pipe).draw(&window);
            (*pipe).move();
        }

        spawnElapsed += pipeSpawnClock.restart().asSeconds();
        if(spawnElapsed >= 2){
            spawnElapsed = 0.0;
            pipes.push_back(new Pipe());
            if (pipes.size()>=4){
                score++;
            }
            if (pipes.size()>10){
                pipes.erase(pipes.begin());
            }
        }

        window.display();
        if(character.checkColision(pipes)){
            window.clear();
            window.draw(spriteBackground);
            scoreBoard.setString("Score: "+to_string(score));
            window.draw(scoreBoard);
            character.draw(&window);
                    for (Pipe* pipe: pipes){
            (*pipe).draw(&window);
            (*pipe).move();
        }
            window.display();
            break;
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::MouseWheelScrolled){
                character.mouseScroll(event.mouseWheelScroll.delta);

            }
        }
    }

    while (window.isOpen()){
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    

    return 0;
}