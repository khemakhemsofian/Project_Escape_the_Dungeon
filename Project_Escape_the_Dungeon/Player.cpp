#include "Player.h"

Player::Player(float posX, float posY, float playerSpeed)
    : position(posX, posY), speed(playerSpeed), isGrounded(false), canJump(false), movingLeft(false), movingRight(false), jumping(false), jumpForce(500.0f), gravity(981.0f), hasKey(false) {
    playershape.setSize(sf::Vector2f(50.0f, 50.0f));
    playershape.setPosition(position);
}

void Player::buff() {
    if (potionClock.getElapsedTime().asSeconds() < 2.0f) {
        speed *= 2;
    }
    else {
        speed = 150.0f;
    }
}

void Player::update(float deltaTime, Map& map) {
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

    // Gérer les collisions avec les murs et les sols
    for (const auto& wall : map.getWalls()) {
        handlePlatformCollision(wall);
    }
    for (const auto& floor : map.getFloors()) {
        handlePlatformCollision(floor);
    }
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
        if (velocity.y > 0) { // Collision par le bas
            position.y = platform.getPosition().y - playershape.getSize().y;
            isGrounded = true;
            canJump = true;
        }
        else if (velocity.y < 0) { // Collision par le haut
            position.y = platform.getPosition().y + platform.getSize().y;
            velocity.y = 0;
        }
        else if (velocity.x > 0) { // Collision par la droite
            position.x = platform.getPosition().x - playershape.getSize().x;
            velocity.x = 0;
        }
        else if (velocity.x < 0) { // Collision par la gauche
            position.x = platform.getPosition().x + platform.getSize().x;
            velocity.x = 0;
        }
    }
    else {
        isGrounded = false;
    }
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(playershape);
}

//bool Player::checkCollision(const Entity& other) const {
//    return playershape.getGlobalBounds().intersects(other.getGlobalBounds());
//}

sf::Vector2f Player::getPosition() const {
    return position;
}

sf::FloatRect Player::getGlobalBounds() const {
    return playershape.getGlobalBounds();
}