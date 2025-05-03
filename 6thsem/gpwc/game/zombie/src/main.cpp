#include<SFML/Graphics.hpp>
#define WIDTH 1920
#define HEIGHT 1080


using namespace sf;

int main(){
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Zombie");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background_sheet.png");
    View mainView(FloatRect(0, 0, WIDTH, HEIGHT));

    VertexArray background;
    background.setPrimitiveType(Quads);
    background.resize(10*10*4);
    int tile=0;

    for(int i=0; i<10; i++){
        int topLeftY = i*49;
        background[i*4+0].position = Vector2f(0, topLeftY);
        background[i*4+1].position = Vector2f(49, topLeftY);
        background[i*4+2].position = Vector2f(0 ,49 + topLeftY);
        background[i*4+3].position = Vector2f(49, 49 + topLeftY);
        background[i*4+0].texCoords = Vector2f(0, 0);
        background[i*4+1].texCoords = Vector2f(49, 0);
        background[i*4+2].texCoords = Vector2f(49, 49);
        background[i*4+3].texCoords = Vector2f(0, 49);
        tile++;
    }


    // background[0].position = Vector2f(0, 0);
    // background[1].position = Vector2f(49, 0);
    // background[2].position = Vector2f(49,49);
    // background[3].position = Vector2f(0, 49);




    while(window.isOpen()){
        Event event;
        window.pollEvent(event);
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }



        window.clear();

        window.setView(mainView);
        window.draw(background, &backgroundTexture);



        
        window.display();
        

    }

    return 0;

}