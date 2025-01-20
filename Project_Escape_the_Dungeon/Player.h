#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public Entity {
public:
    Player(int posX, int posY, float playerSpeed);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    void handleInput(sf::RenderWindow& window);
    bool checkCollision(const Entity& other) const override; 
    sf::RectangleShape playershape;
private:
    bool movingLeft;
    bool movingRight;
    bool jumping;
    bool canJump; 
    float speed;
    float jumpForce;
    float gravity;
    sf::Vector2f position;
    sf::Vector2f velocity;
};
#endif // !PLAYER_H