#include "Key.h"

Key::Key(int posX, int posY) {
    position = sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY));
    keyShape.setSize(sf::Vector2f(20.0f, 20.0f));
    keyShape.setFillColor(sf::Color::Yellow);
    keyShape.setPosition(position);
    tag = "Key";
}

void Key::interact(Player& player) {
    player.hasKey = true;
	std::cout << "You got the key!" << std::endl;
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

bool Key::checkCollision(const Entity& other) const {
	return keyShape.getGlobalBounds().intersects(other.getGlobalBounds());
}

//void Key::handleInteractableCollision(Player& player) {
//    if (player.playershape.getGlobalBounds().intersects(this->getGlobalBounds())) {
//        this->interact(player);
//    }
//}