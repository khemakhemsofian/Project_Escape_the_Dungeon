#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(int posX, int posY, float ennemiSpeed, Player& player)
    : Ennemi(posX, posY, ennemiSpeed), player(player) {
    this->position = sf::Vector2f(posX, posY);
    this->speed = ennemiSpeed;
    this->ennemishape.setSize(sf::Vector2f(50.0f, 50.0f)); // Exemple de taille
    this->ennemishape.setPosition(this->position);
}

void ChaserEnemy::update(float deltaTime) {
    // Impl�mentation de la mise � jour
}

void ChaserEnemy::draw(sf::RenderWindow& window) const {
    window.draw(this->ennemishape);
}

bool ChaserEnemy::checkCollision(const Entity& other) const {
    // Impl�mentation de la v�rification de collision
    return false;
}