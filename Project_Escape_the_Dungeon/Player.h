#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Ennemi.h"
//#include "Interactable.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public Entity {
public:
    Player(float posX, float posY, float playerSpeed); 
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void handleInput(sf::RenderWindow& window);
    bool checkCollision(const Entity& other) const override;
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const override;
    void handlePlatformCollision(const sf::RectangleShape& platform);
    sf::RectangleShape playershape;
    bool hasKey;
    float speed;
private:
    bool movingLeft;
    bool movingRight;
    bool jumping;
    bool canJump;
    bool isGrounded;
    
    float jumpForce;
    float gravity;
    sf::Vector2f position;
    sf::Vector2f velocity;
};

#endif // PLAYER_H