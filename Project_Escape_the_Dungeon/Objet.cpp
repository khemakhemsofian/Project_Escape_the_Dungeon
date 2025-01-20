#include "Objet.h"

Objet::Objet(int posX, int posY, float objetSpeed) {
    position = sf::Vector2f(posX, posY);
    velocity = sf::Vector2f(0.0f, 0.0f);
    speed = objetSpeed;
    objetshape.setSize(sf::Vector2f(50, 50));
    objetshape.setFillColor(sf::Color::Blue);
    objetshape.setPosition(position);
    tag = "Objet";
}

void Objet::update(float deltaTime) {
    velocity.x = speed;
    position += velocity * deltaTime;
    objetshape.setPosition(position);
}

void Objet::draw(sf::RenderWindow& window) const {
    window.draw(objetshape);
}


