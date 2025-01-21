#include "Potion.h"

Potion::Potion(int posX, int posY) {
    position = sf::Vector2f(posX, posY);
    potionShape.setSize(sf::Vector2f(30, 30));
    potionShape.setFillColor(sf::Color::Green);
    potionShape.setPosition(position);
    tag = "Potion";
}

void Potion::interact(Player& player) {
    player.speed += 10.0f; 
}

void Potion::update(float deltaTime) {
    // Pas de mise à jour spécifique pour la potion
}

void Potion::draw(sf::RenderWindow& window) const {
    window.draw(potionShape);
}

sf::FloatRect Potion::getGlobalBounds() const {
    return potionShape.getGlobalBounds();
}
void Potion::handleInteractableCollision(Player& player) {
    if (player.playershape.getGlobalBounds().intersects(this->getGlobalBounds())) {
        this->interact(player);
    }
}