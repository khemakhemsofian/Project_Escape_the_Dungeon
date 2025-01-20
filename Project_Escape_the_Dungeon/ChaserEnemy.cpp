#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(int posX, int posY, float ennemiSpeed, Player& player)
    : Ennemi(posX, posY, ennemiSpeed), player(player) {
    this->position = sf::Vector2f(posX, posY);
    this->speed = ennemiSpeed;
    this->ennemishape.setSize(sf::Vector2f(50.0f, 50.0f)); // Exemple de taille
    this->ennemishape.setPosition(this->position);
}

void ChaserEnemy::update(float deltaTime) {
    // Implémentation de la mise à jour
}

void ChaserEnemy::draw(sf::RenderWindow& window) const {
    window.draw(this->ennemishape);
}

bool ChaserEnemy::checkCollision(const Entity& other) const {
    // Implémentation de la vérification de collision
    return false;
}