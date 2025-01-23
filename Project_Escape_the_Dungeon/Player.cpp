#include "Player.h"


Player::Player(float posX, float posY, float playerSpeed)
    : position(posX, posY), speed(playerSpeed), isGrounded(false), canJump(false), movingLeft(false), movingRight(false), jumping(false), jumpForce(500.0f), gravity(981.0f), hasKey(false) {
    playershape.setSize(sf::Vector2f(50.0f, 50.0f));
    playershape.setPosition(position);
}

void Player::buff() {
    if (potionClock.getElapsedTime().asSeconds() < 2.0f)
    {
        speed *= 2;
	}
	else {
		speed = 150.0f;
    }
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

    if (jumping && canJump) {
        velocity.y = -jumpForce;
        canJump = false;
        isGrounded = false;
    }

    if (!isGrounded) {
        velocity.y += gravity * deltaTime;
    }
    else {
        velocity.y = 0;
    }

    position += velocity * deltaTime;
    playershape.setPosition(position);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded) {
        jumping = true;
    }
    else {
        jumping = false;
    }
}

void Player::handlePlatformCollision(const sf::RectangleShape& platform) {
    if (playershape.getGlobalBounds().intersects(platform.getGlobalBounds())) {
        if (velocity.y > 0) { 
            position.y = platform.getPosition().y - playershape.getSize().y;
            isGrounded = true;
            canJump = true;
        }
    }
    else {
        isGrounded = false;
    }
}



void Player::draw(sf::RenderWindow& window) const {
    window.draw(playershape);
}

bool Player::checkCollision(const Entity& other) const {
    return playershape.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::Vector2f Player::getPosition() const {
    return position;
}

sf::FloatRect Player::getGlobalBounds() const {
    return playershape.getGlobalBounds();
}