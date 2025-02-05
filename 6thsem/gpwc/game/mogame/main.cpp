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
    static float speed, acceleration;

    static int gap;
    Sprite upper, lower;
    Texture texture;
    Clock clock;
    bool passed;


    static Clock spawnClock;
    static double spawnElapsed;

    public:
    static int score;
    static vector<Pipe*> pipes;
    static Sprite coin;
    static Texture coin_t;
    Pipe(){
        this->clock = Clock();
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

        this->upper.setPosition(Vector2f(WIDTH-width, 0));
        this->lower.setPosition(Vector2f(WIDTH-width, HEIGHT-lower_height));

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
        return this->upper.getPosition().x <-50;
    }

    static void drawAll(RenderWindow* window){
        window->draw(coin);
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
        if(spawnElapsed >= 0.7/speed){
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
float Pipe::speed = 0.35;
float Pipe::acceleration = 0.04;
int Pipe::gap = 200;

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

class Background{
        Sprite sa,sb,sc,sd,se;
        Texture ta, tb, tc, td, te;

        public:
        Background(){
            ta.loadFromFile("assets/background/1.png");
            tb.loadFromFile("assets/background/2.png");
            tc.loadFromFile("assets/background/3.png");
            td.loadFromFile("assets/background/4.png");
            te.loadFromFile("assets/background/5.png");

            sa.setTexture(ta);
            sb.setTexture(tb);
            sc.setTexture(tc);
            sd.setTexture(td);
            se.setTexture(te);

            sa.scale(Vector2f(WIDTH/ta.getSize().x,HEIGHT/ta.getSize().y));
            sb.scale(Vector2f(WIDTH/tb.getSize().x,HEIGHT/tb.getSize().y));
            sc.scale(Vector2f(WIDTH/tc.getSize().x,HEIGHT/tc.getSize().y));
            sd.scale(Vector2f(WIDTH/td.getSize().x,HEIGHT/td.getSize().y));
            se.scale(Vector2f(WIDTH/te.getSize().x,HEIGHT/te.getSize().y));
        
        }

        void draw(RenderWindow *window){
            window->draw(sa);
            window->draw(sb);
            window->draw(sc);
            window->draw(sd);
            window->draw(se);
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

    Background background = Background();
    Character character = Character();

    Pipe::pipes.push_back(new Pipe());
    sf::Event event;



    Pipe::coin_t.loadFromFile("assets/coin.png");
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
            // background.draw(&window);
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