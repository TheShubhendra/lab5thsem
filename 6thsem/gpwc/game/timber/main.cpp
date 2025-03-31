#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;
using namespace std;



int main(){
    
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Timber", Style::Default);

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);


    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");

    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(WIDTH/2-treeSprite.getLocalBounds().width/2,0);
    // treeSprite.setScale(1, 1.2);

    Sprite auxialiryTree1;
    auxialiryTree1.setTexture(treeTexture);
    auxialiryTree1.setScale(0.5,0.87);
    auxialiryTree1.setPosition(130, 0);

    Sprite auxialiryTree2;
    auxialiryTree2.setTexture(treeTexture);
    auxialiryTree2.setScale(0.3, 0.77);
    auxialiryTree2.setPosition(WIDTH - 435, 0);

    Sprite auxialiryTree3;
    auxialiryTree3.setTexture(treeTexture);

    Sprite auxialiryTree4;
    auxialiryTree4.setTexture(treeTexture);
    
    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");


    Sprite cloud1, cloud2, cloud3;
    cloud1.setTexture(cloudTexture);
    cloud2.setTexture(cloudTexture);
    cloud3.setTexture(cloudTexture);

    cloud1.setPosition(-cloud1.getGlobalBounds().width, -10);
    cloud2.setPosition(WIDTH/2-cloud2.getGlobalBounds().width,30);
    cloud3.setPosition(WIDTH/2, 75);

    cloud1.setScale(1.3, 1);
    cloud2.setScale(0.7, 1);

    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");

    Sprite beeSprite;
    beeSprite.setTexture(beeTexture);



    bool isBeeActive;
    int beeSpeed;
    bool isCloud1Active, isCloud2Active;
    float cloud1Speed, cloud2Speed;



    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");

    Texture axeTexture;
    axeTexture.loadFromFile("graphics/axe.png");
    Sprite axeSprite;
    axeSprite.setTexture(axeTexture);
    

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(-1.5,1.5);
    // playerSprite.move(-playerSprite.getGlobalBounds().width, 100);
    playerSprite.setPosition(WIDTH/2-playerSprite.getGlobalBounds().width, HEIGHT/2 + playerSprite.getGlobalBounds().height/2);
    // playerSprite.setPosition(WIDTH/2 - playerSprite.getGlobalBounds().width/2 - treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height-playerSprite.getGlobalBounds().height);
    std::cout << "Player sprite " << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << "\n";
    axeSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + playerSprite.getGlobalBounds().height/2 - 35);
    
    // axeSprite.setOrigin(axeSprite.getGlobalBounds().width, axeSprite.getGlobalBounds().height);
    // axeSprite.setRotation(180);

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

    
    for(int i=0; i<5; i++){
        bool isLeft = rand()%2==1;
        Sprite* branch = new Sprite();
        branch->setTexture(branchTexture);
        int yPos = 175*i;
        if(isLeft){
            if(branch->getScale().x<0){
                branch->setScale(1,1);
            }
            branch->setPosition(WIDTH/2 + branch->getGlobalBounds().width/2 - 70, yPos);
        }else{
            if(branch->getScale().x>0){
                branch->setScale(-1,1);
            }
            branch->setPosition(WIDTH/2 - branch->getGlobalBounds().width/2 + 70, yPos);
        }

        branches.push_back(branch);
    }

    Event event;

    int branchSpeed = 5;

    Clock clock;
    RectangleShape timeBar;
    float timeBarStartWidth= 200;
    float timeBarHeight = 30;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(WIDTH/2 - timeBarStartWidth/2, 50);



    bool paused=true;
    int score = 0;
    Text messageText;
    Text scoreText;

    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    messageText.setFont(font);
    scoreText.setFont(font);
    messageText.setString("Press Enter to Start!!!!");
    scoreText.setString("Score: 0");

    scoreText.setCharacterSize(75);
    messageText.setCharacterSize(100);

    scoreText.setColor(Color::White);
    messageText.setColor(Color::White);

    FloatRect textRect = messageText.getLocalBounds();

    messageText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    playerSprite.setPosition(WIDTH/2 + playerSprite.getLocalBounds().width/2 - treeSprite.getLocalBounds().width, treeSprite.getLocalBounds().height-playerSprite.getLocalBounds().height);


    scoreText.setPosition(20, 20);
    while (window.isOpen())
    {

        while(window.pollEvent(event));
        /*
        Handle Player Input
        */


        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Return)){
            paused = false;
        }
        if (!paused){
            std::cout << "Player sprite " << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << "\n";

            if (Keyboard::isKeyPressed(Keyboard::Left)){

                playerSprite.setScale(-1.5,1.5);
                playerSprite.setPosition(WIDTH/2 + playerSprite.getLocalBounds().width/2 - treeSprite.getLocalBounds().width, treeSprite.getLocalBounds().height-playerSprite.getLocalBounds().height);
                axeSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + playerSprite.getLocalBounds().height/2);
                for(Sprite* branch: branches){
                    branch->setPosition(branch->getPosition().x, branch->getPosition().y + branchSpeed);
                }
                // std::cout << "Player sprite " << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << "\n";

            }
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                // axeSprite.setRotation(90);
                playerSprite.setScale(1.5,1.5);
                playerSprite.setPosition(WIDTH/2 - playerSprite.getLocalBounds().width/2 + treeSprite.getLocalBounds().width, treeSprite.getLocalBounds().height-playerSprite.getLocalBounds().height);
                axeSprite.setPosition(playerSprite.getPosition().x - playerSprite.getLocalBounds().width, playerSprite.getPosition().y + playerSprite.getGlobalBounds().height/2);
                for(Sprite* branch: branches){
                    branch->setPosition(branch->getPosition().x, branch->getPosition().y + branchSpeed);
                }
                // std::cout << "Player sprite " << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << "\n";

            }



            /***********************************
             * Update the scene                *
            ************************************/
            if(!isBeeActive){
                srand((int)time(0));
                beeSpeed = (rand()%100) + 100;

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
                
                cloud1Speed = (rand()%20) + 1;
                cloud1.setPosition(-cloud1.getGlobalBounds().width, 0);
                isCloud1Active = true;
            }else{
                cloud1.setPosition(cloud1.getPosition().x + cloud1Speed/100, 0);

                if (cloud1.getPosition().x > WIDTH+cloud1.getGlobalBounds().width){
                    isCloud1Active = false;
                }
            }

            if(!isCloud2Active){

                cloud2Speed = (rand()%20) + 1;
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
            // branch->setPosition(branch->getPosition().x, branch->getPosition().y + branchSpeed);
        }


    }
        /***********************************
         * Draw the scene                  *
        ************************************/
        window.clear();
        window.draw(backgroundSprite);
        window.draw(cloud1);
        window.draw(cloud2);
        window.draw(cloud3);
        window.draw(auxialiryTree1);
        window.draw(auxialiryTree2);
        // window.draw(auxialiryTree3);
        // window.draw(auxialiryTree4);
        window.draw(treeSprite);
        for(Sprite* branch: branches){
            window.draw(*branch);
        }
        window.draw(playerSprite);
        window.draw(axeSprite);
        window.draw(beeSprite);
        if (!paused){
            window.draw(timeBar);
            window.draw(scoreText);
        }else{
            window.draw(messageText);
        }
        window.display();

    }
    
    
    
};