#include<SFML/Graphics.hpp>
#include "player.hpp"
#include<iostream>

#define WIDTH 1920
#define HEIGHT 1080


using namespace sf;
using namespace std;
enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };
int main(){

    State state = State::PLAYING;

    Vector2f resolution;
    IntRect arena;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "Zombie");
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background_sheet.png");

    Player player;
    Clock clock;
    int totalGameTime = 0;
    // mainView.setRotation(45);

    VertexArray background;
    background.setPrimitiveType(Quads);
    const int ROW_COUNT = 100;
    const int COL_COUNT = 100;
    background.resize(ROW_COUNT*COL_COUNT*4);
    int tile=0;

    

    for(int row=0; row<ROW_COUNT; row++){
        for(int col=0; col<COL_COUNT; col++){
            Vector2f topLeft(col*49, row*49);
            int idx = 4*row*COL_COUNT + 4*col;
            background[idx+0].position = topLeft;
            background[idx+1].position = Vector2f(topLeft.x + 49, topLeft.y);
            background[idx+2].position = Vector2f(topLeft.x + 49, topLeft.y + 49);
            background[idx+3].position = Vector2f(topLeft.x, topLeft.y + 49);
            Vector2f spriteTopLeft;
            if (row==0 || row == ROW_COUNT-1 || col==0 || col==COL_COUNT-1){
                spriteTopLeft = Vector2f(0, 3*49);
            }else{
                spriteTopLeft = Vector2f(0, rand()%3 * 49);
            }

            background[idx+0].texCoords = spriteTopLeft;
            background[idx+1].texCoords = Vector2f(49, spriteTopLeft.y);
            background[idx+2].texCoords = Vector2f(49, spriteTopLeft.y + 49);
            background[idx+3].texCoords = Vector2f(0, spriteTopLeft.y + 49);
        }
    }

    

    bool acceptInput = true;
    while(window.isOpen()){
        Event event;
        if (state==State::PLAYING){
            Time time = clock.restart();
            window.pollEvent(event);
            if(event.type==Event::KeyReleased){
                player.stopMove();
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }

            if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
                player.startMove(Direction::LEFT);
                
            }
            if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
                player.startMove(Direction::RIGHT);
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
                player.startMove(Direction::UP);
            }
            if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
                player.startMove(Direction::DOWN);
            }
            player.update(time.asSeconds(), Mouse::getPosition());

            totalGameTime += time.asSeconds();
        }

        

        mainView.setCenter(player.getCenter());

        window.clear();

        window.setView(mainView);
        window.draw(background, &backgroundTexture);
        window.draw(player.getSprite());



        
        window.display();
        

    }

    return 0;

}