#include <SFML/Graphics.hpp>
#include <iostream>
#include<stdlib.h>
#include <unistd.h>
#include "pipe.hpp"

#define WIDTH 1366
#define HEIGHT 768
#define PIPE_MOVEMENT_SPEED 0.05


using namespace std;
using namespace sf;

class Character{

    Texture texture1, texture2, texture3;
    Clock clock;
    float secondsElapsed = 0;
    int currentTexture = 0;

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
        secondsElapsed += clock.getElapsedTime().asSeconds();
        if (secondsElapsed > 3){
            clock.restart();
            secondsElapsed = 0;
            if (currentTexture == 0){
                currentTexture = 1;
                sprite.setTexture(texture2);
            }else{
                currentTexture = 0;
                sprite.setTexture(texture1);
            }
            
        }
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

    Character character = Character();

    Pipe::pipes.push_back(new Pipe());
    sf::Event event;



    // Pipe::coin_t.loadFromFile("assets/coin.png");
    // Pipe::coin.setTexture(Pipe::coin_t);
    // Pipe::coin.setPosition(0, 0);
    // Pipe::coin.scale(Vector2f(0.3, 0.3));

    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();
        // background.draw(&window);
        window.draw(spriteBackground);
        scoreBoard.setString("Score: "+to_string(Pipe::score));
        character.draw(&window);
        Pipe::drawAll(&window);
        window.draw(scoreBoard);

        window.display();
        if(character.checkColision(Pipe::pipes)){
            window.clear();
            window.draw(spriteBackground);
            scoreBoard.setString("Score: "+to_string(Pipe::score));
            window.draw(scoreBoard);
            character.draw(&window);
            Pipe::drawAll(&window);
            window.display();
            break;
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
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