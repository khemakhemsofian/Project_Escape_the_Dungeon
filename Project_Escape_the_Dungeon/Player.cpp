#include "Player.h"
#include "Ennemi.h"

Player::Player(int posX, int posY, float playerSpeed)
    : position(posX, posY), velocity(0.0f, 0.0f), movingLeft(false), movingRight(false), jumping(false), canJump(true), speed(playerSpeed), jumpForce(150.0f), gravity(300.0f) {
    playershape.setSize(sf::Vector2f(50, 50));
    playershape.setFillColor(sf::Color::Green);
    playershape.setPosition(position);
    tag = "Player"; 
}

void Player::update(float deltaTime) {
    if (movingLeft) {
        velocity.x = -speed;
    }
    else if (movingRight) {
        velocity.x = speed;
    }
    else {
        velocity.x = 0;
    }

    if (jumping) {
        velocity.y = -jumpForce;
        jumping = false;
    }
    velocity.y += gravity * deltaTime;
    position += velocity * deltaTime;
    playershape.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(playershape);
}

void Player::handleInput(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        movingLeft = true;
    }
    else {
        movingLeft = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movingRight = true;
    }
    else {
        movingRight = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (canJump) {
            jumping = true;
            canJump = false;
            std::cout << "Jumping" << std::endl;
        }
    }
    else {
        canJump = true;
    }
}

bool Player::checkCollision(const Entity& other) const {
	const Player* player = dynamic_cast<const Player*>(&other);
    if (player)
    {
        return playershape.getGlobalBounds().intersects(player->playershape.getGlobalBounds());
    }

	const Ennemi* ennemi = dynamic_cast<const Ennemi*>(&other);
	if (ennemi)
	{
		return playershape.getGlobalBounds().intersects(ennemi->ennemishape.getGlobalBounds());
	}
	return false;
}
