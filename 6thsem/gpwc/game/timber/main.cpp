#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath> // For sin, cos
#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;
using namespace std;

int main() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Timber", Style::Fullscreen);

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("graphics/background.png");

    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    Texture treeTexture;
    treeTexture.loadFromFile("graphics/tree.png");

    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(WIDTH / 2 - treeSprite.getLocalBounds().width / 2, 0);

    Texture cloudTexture;
    cloudTexture.loadFromFile("graphics/cloud.png");

    Sprite cloud1, cloud2, cloud3;
    cloud1.setTexture(cloudTexture);
    cloud2.setTexture(cloudTexture);
    cloud3.setTexture(cloudTexture);

    cloud1.setPosition(-cloud1.getGlobalBounds().width, -10);
    cloud2.setPosition(WIDTH / 2 - cloud2.getGlobalBounds().width, 30);
    cloud3.setPosition(WIDTH / 2, 75);

    cloud1.setScale(1.3, 1);
    cloud2.setScale(0.7, 1);

    Texture beeTexture;
    beeTexture.loadFromFile("graphics/bee.png");

    Sprite beeSprite;
    beeSprite.setTexture(beeTexture);

    // Circular motion variables
    float radius = 150.0f; // Radius of the circular motion
    float angle = 0.0f;    // Initial angle
    float centerX = WIDTH / 2;  // Center of the circle (x)
    float centerY = HEIGHT / 2; // Center of the circle (y)
    float beeSpeed = 0.05f; // Speed of the circular motion

    bool isBeeActive;

    Texture playerTexture;
    playerTexture.loadFromFile("graphics/player.png");

    Texture axeTexture;
    axeTexture.loadFromFile("graphics/axe.png");
    Sprite axeSprite;
    axeSprite.setTexture(axeTexture);

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setScale(1.5, 1.5);
    playerSprite.setPosition(WIDTH / 2 - playerSprite.getGlobalBounds().width / 2 - treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height - playerSprite.getGlobalBounds().height);
    axeSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y);

    Event event;

    Clock clock;
    RectangleShape timeBar;
    float timeBarStartWidth = 200;
    float timeBarHeight = 20;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition(WIDTH / 2 - timeBarStartWidth / 2, 50);

    bool paused = true;
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

    scoreText.setFillColor(Color::White);
    messageText.setFillColor(Color::White);

    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(WIDTH / 2, HEIGHT / 2);

    scoreText.setPosition(20, 20);

    while (window.isOpen()) {

        while (window.pollEvent(event));

        // Handle Player Input
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            paused = false;
        }

        if (!paused) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                playerSprite.setPosition(WIDTH / 2 - playerSprite.getGlobalBounds().width / 2 - treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height - playerSprite.getGlobalBounds().height);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                playerSprite.setPosition(WIDTH / 2 - playerSprite.getGlobalBounds().width / 2 + treeSprite.getGlobalBounds().width, treeSprite.getGlobalBounds().height - playerSprite.getGlobalBounds().height);
            }

            // Update bee position for circular motion
            angle += beeSpeed;  // Increment the angle to move the bee

            // Calculate the new position using sine and cosine for circular motion
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);

            // Update bee position
            beeSprite.setPosition(x, y);

            // Keep the angle within 0 to 2*PI to prevent it from growing too large
            if (angle > 2 * M_PI) {
                angle -= 2 * M_PI;
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
        window.draw(treeSprite);
        window.draw(playerSprite);
        window.draw(axeSprite);
        window.draw(beeSprite);
        if (!paused) {
            window.draw(timeBar);
            window.draw(scoreText);
        } else {
            window.draw(messageText);
        }
        window.display();
    }
}
