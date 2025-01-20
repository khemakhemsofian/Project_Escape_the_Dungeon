#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public Entity {
public:
    Player(int posX, int posY, float playerSpeed);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void handleInput(sf::RenderWindow& window);
    bool checkCollision(const Entity& other) const; 
    sf::RectangleShape getShape() const; 
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
    sf::RectangleShape playershape;
};
#endif // !PLAYER_H