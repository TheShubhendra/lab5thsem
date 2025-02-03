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
    const float speed = 0.35;
    RectangleShape upper, lower;
    Clock clock;
    static Clock spawnClock;
    static double spawnElapsed;

    public:
    static int score;
    static vector<Pipe*> pipes;
    Pipe(){
        this->clock = Clock();
        const int gap = 130;
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

    bool isOut(){
        return this->upper.getPosition().x <0;
    }

    static void drawAll(RenderWindow* window){
        for (int i = 0; i < pipes.size(); i++){
            pipes[i]->draw(window);
            pipes[i]->move();
            if (pipes[i]->isOut()){
                pipes.erase(pipes.begin() + i);
            }
            if (pipes[i]->)
        }


        spawnElapsed += spawnClock.restart().asSeconds();
        if(spawnElapsed >= 2){
            spawnElapsed = 0.0;
            Pipe::addPipe();
        }
    }

    static void addPipe(){
        pipes.push_back(new Pipe());
    }
};

std::vector<Pipe*> Pipe::pipes;
double Pipe::spawnElapsed;
Clock Pipe::spawnClock;
int Pipe::score;

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
    while (window.isOpen())
    {

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        window.clear();
        window.draw(spriteBackground);
        scoreBoard.setString("Score: "+to_string(Pipe::score));
        window.draw(scoreBoard);
        character.draw(&window);
        

        Pipe::drawAll(&window);


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