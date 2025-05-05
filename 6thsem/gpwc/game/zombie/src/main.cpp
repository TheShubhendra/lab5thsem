#include<SFML/Graphics.hpp>
#include "player.hpp"
#include<iostream>

#define WIDTH 1920
#define HEIGHT 1080


using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Zombie");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background_sheet.png");
    View mainView(FloatRect(0, 0, WIDTH, HEIGHT));

    Player player;

    mainView.setCenter(player.getCenter());
    // mainView.setRotation(45);

    VertexArray background;
    background.setPrimitiveType(Quads);
    const int ROW_COUNT = 20;
    const int COL_COUNT = 20;
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
        window.pollEvent(event);
        if (acceptInput){
            acceptInput = false;
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }
    
            if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
                player.move(Direction::LEFT);
                
            }
            if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
                player.move(Direction::RIGHT);
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
                player.move(Direction::UP);
            }
            if(Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
                player.move(Direction::DOWN);
            }


        }
        if(!acceptInput && event.type == Event::KeyReleased){
            acceptInput = true;
        }


        



        window.clear();

        window.setView(mainView);
        window.draw(background, &backgroundTexture);
        window.draw(player.getSprite());



        
        window.display();
        

    }

    return 0;

}