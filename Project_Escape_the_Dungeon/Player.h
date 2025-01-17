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
	void  handleInput(sf::RenderWindow& window);
private:
	bool movingLeft;
	bool movingRight;
	bool jumping;
	bool canJump;
	float speed;
	float gravity = 300.0f;
	float jumpForce = 150.0f;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::RectangleShape playershape;
};
#endif // !PLAYER_H

