#include <SFML/Graphics.hpp>
#include "bat.hpp"

#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;
int main(){
    VideoMode vm(WIDTH, HEIGHT);
    RenderWindow window(vm, "Pong!");
    Vector2f batSize = Vector2f(150, 25);
    Bat bat = Bat(Vector2f(0, HEIGHT-batSize.y), batSize);
    Event event;
    while(window.isOpen()){
        window.pollEvent(event);
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            break;
        }

        // Handle input
        if (Keyboard::isKeyPressed(Keyboard::Left)){
            bat.move(Direction::LEFT);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            bat.move(Direction::RIGHT);
        }


        window.clear();
        // Draw here
        window.draw(bat.sprite);










        window.display();


    }

    return 0;
}