#include "Key.h"

Key::Key(int posX, int posY) {
    position = sf::Vector2f(posX, posY);
    keyShape.setSize(sf::Vector2f(20, 20));
    keyShape.setFillColor(sf::Color::Yellow);
    keyShape.setPosition(position);
    tag = "Key";
}

void Key::interact(Player& player) {
    player.hasKey = true; // Le joueur obtient la clé
}

void Key::update(float deltaTime) {
    // Pas de mise à jour spécifique pour la clé
}

void Key::draw(sf::RenderWindow& window) const {
    window.draw(keyShape);
}

sf::FloatRect Key::getGlobalBounds() const {
    return keyShape.getGlobalBounds();
}
void Key::handleInteractableCollision(Player& player) {
    if (player.playershape.getGlobalBounds().intersects(this->getGlobalBounds())) {
        this->interact(player);
    }
}