#include "ChaserEnemy.h"

ChaserEnemy::ChaserEnemy(int posX, int posY, float ennemiSpeed, Player& player)
    : Ennemi(posX, posY, ennemiSpeed*1.5f), player(player) {
    this->position = sf::Vector2f(posX, posY);
    this->speed = ennemiSpeed;
    this->ennemishape.setSize(sf::Vector2f(50.0f, 50.0f)); 
    this->ennemishape.setPosition(this->position);
	this->ennemishape.setFillColor(sf::Color::Red); 
}

void ChaserEnemy::update(float deltaTime) {
    sf::Vector2f direction = player.getPosition() - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length;
    }
    velocity = direction * speed * deltaTime;
    position += velocity;
    ennemishape.setPosition(position);

    if (checkCollision(player))
    {
        std::cout << "Chaser t'a toucher ahah" << std::endl;
    }
}

void ChaserEnemy::draw(sf::RenderWindow& window) const {
    window.draw(ennemishape);
}

bool ChaserEnemy::checkCollision(const Entity& other) const {
    return ennemishape.getGlobalBounds().intersects(other.getGlobalBounds());
}

sf::FloatRect ChaserEnemy::getGlobalBounds() const {
	return ennemishape.getGlobalBounds();
}