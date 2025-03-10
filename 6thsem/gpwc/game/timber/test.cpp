#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;

int main(){
    
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Timber");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    while (window.isOpen())
    {
        /*
        Handle Player Input
        */


        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }
    return 0;
}