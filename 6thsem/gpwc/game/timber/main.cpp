#include <SFML/Graphics.hpp>

#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;
using namespace std;


int main(){
    VideoMode vm(WIDTH, HEIGHT);
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
    playerSprite.setPosition(WIDTH/2 - playerSprite.getGlobalBounds().width/2 - treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height-playerSprite.getGlobalBounds().height);


    Texture branchTexture;
    branchTexture.loadFromFile("graphics/branch.png");


    Sprite branch1Sprite;
    branch1Sprite.setTexture(branchTexture);
    branch1Sprite.setPosition(WIDTH/2 + branch1Sprite.getGlobalBounds().width/2 - 70, 500);


    Sprite branch2Sprite;
    branch2Sprite.setTexture(branchTexture);
    branch2Sprite.scale(-1,1);
    branch2Sprite.setPosition(WIDTH/2 - branch2Sprite.getGlobalBounds().width/2 + 70, 100);

    
    vector<Sprite*> branches;
    branches.push_back(&branch1Sprite);
    branches.push_back(&branch2Sprite);

    
    for(int i=0; i<2; i++){
        bool isLeft = rand()%2==1;
        Sprite branch;
        branch.setTexture(branchTexture);
        int yPos = 100*i + 100;
        if(isLeft){
            if(branch.getScale().x<0){
                branch.setScale(1,1);
            }
            branch.setPosition(WIDTH/2 + branch.getGlobalBounds().width/2 - 70, yPos);
        }else{
            if(branch.getScale().x>0){
                branch.setScale(-1,1);
            }
            branch.setPosition(WIDTH/2 - branch.getGlobalBounds().width/2 + 70, yPos);
        }

        // branches.push_back(&branch);
    }

    Event event;

    int branchSpeed = 1;

    while (window.isOpen())
    {
        /*
        Handle Player Input
        */


        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)){
            playerSprite.setPosition(WIDTH/2 - playerSprite.getGlobalBounds().width/2 - treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height-playerSprite.getGlobalBounds().height);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)){
            playerSprite.setPosition(WIDTH/2 - playerSprite.getGlobalBounds().width/2 + treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height-playerSprite.getGlobalBounds().height);
        }
        

        while(window.pollEvent(event));


        /***********************************
         * Update the scene                *
        ************************************/
        if(!isBeeActive){
            srand((int)time(0));
            beeSpeed = (rand()%200) + 200;

            float height = (rand()%500) + 400;
            beeSprite.setPosition(WIDTH, height);

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

            if (cloud1.getPosition().x > WIDTH+cloud1.getGlobalBounds().width){
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

    

        for(Sprite* branch: branches){
            if (branch->getPosition().y > treeSprite.getGlobalBounds().height - branch->getGlobalBounds().height){
                bool isLeft = rand()%2==1;
                if(isLeft){
                    if(branch->getScale().x<0){
                        branch->setScale(1,1);
                    }
                    branch->setPosition(WIDTH/2 + branch->getGlobalBounds().width/2 - 70, -branch->getGlobalBounds().height);
                }else{
                    if(branch->getScale().x>0){
                        branch->setScale(-1,1);
                    }
                    branch->setPosition(WIDTH/2 - branch->getGlobalBounds().width/2 + 70, -branch->getGlobalBounds().height);
                }
            }
            branch->setPosition(branch->getPosition().x, branch->getPosition().y + branchSpeed);
        }

    


        /***********************************
         * Draw the scene                  *
        ************************************/
        window.draw(backgroundSprite);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);
        window.draw(treeSprite);
        for(Sprite* branch: branches){
            window.draw(*branch);
        }
        window.draw(playerSprite);
        window.draw(beeSprite);



        window.display();
        window.clear();
    }
    


};