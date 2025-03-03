#include <SFML/Graphics.hpp>

#define WIDTH 1920

using namespace sf;


int main(){
    VideoMode vm(WIDTH, 1080);
    RenderWindow window(vm, "Timber");

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);


    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");


    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(WIDTH/2-treeSprite.getLocalBounds().width/2,0);
    
    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");


    Sprite cloud1, cloud2, cloud3;
    cloud1.setTexture(cloudTexture);
    cloud2.setTexture(cloudTexture);
    cloud3.setTexture(cloudTexture);

    cloud2.setPosition(WIDTH-cloud2.getGlobalBounds().width,0);
    cloud3.setPosition(WIDTH/2, 0);

    cloud1.setScale(1.3, 1);
    cloud2.setScale(0.7, 1);

    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");

    Sprite beeSprite;
    beeSprite.setTexture(beeTexture);


    Clock clock;

    bool isBeeActive;
    int beeSpeed;
    bool isCloud1Active, isCloud2Active;
    float cloud1Speed, cloud2Speed;



    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(1.5,1.5);
    playerSprite.setPosition(WIDTH/2 - playerSprite.getGlobalBounds().width/2, treeSprite.getGlobalBounds().height-playerSprite.getGlobalBounds().height);


    Sprite branch

    Event event;

    while (window.isOpen())
    {
        /*
        Handle Player Input
        */


        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        while(window.pollEvent(event));


        /***********************************
         * Update the scene                *
        ************************************/
        if(!isBeeActive){
            srand((int)time(0));
            beeSpeed = (rand()%200) + 200;

            float height = (rand()%500) + 400;
            beeSprite.setPosition(1980, height);

            isBeeActive=true;
        }else{
            beeSprite.setPosition(beeSprite.getPosition().x - beeSpeed/100, beeSprite.getPosition().y);
            if(beeSprite.getPosition().x < -beeSprite.getGlobalBounds().width){
                isBeeActive = false;
            }
        }

        if(!isCloud1Active){

            cloud1Speed = (rand()%100) + 50;
            cloud1.setPosition(0,0);
            isCloud1Active = true;
        }else{
            cloud1.setPosition(cloud1.getPosition().x + cloud1Speed/100, 0);

            if (cloud1.getPosition().x > 1080+cloud1.getGlobalBounds().width){
                isCloud1Active = false;
            }
        }

        if(!isCloud2Active){

            cloud2Speed = (rand()%100) + 50;
            cloud2.setPosition(1910,0);
            isCloud2Active = true;
        }else{
            cloud2.setPosition(cloud2.getPosition().x - cloud2Speed/100, 0);

            if (cloud2.getPosition().x < -cloud2.getGlobalBounds().width){
                isCloud2Active = false;
            }
        }



        /***********************************
         * Draw the scene                  *
        ************************************/
        window.draw(backgroundSprite);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);
        window.draw(treeSprite);
        window.draw(playerSprite);
        window.draw(beeSprite);



        window.display();
        window.clear();
    }
    


};