#include "Ennemi.h"
#include "Interactable.h"
#include "Player.h"
#include "ChaserEnemy.h"

Ennemi::Ennemi(int posX, int posY, float ennemiSpeed) {
    position = sf::Vector2f(posX, posY);
    velocity = sf::Vector2f(0.0f, 0.0f);
    speed = ennemiSpeed;
    ennemishape.setSize(sf::Vector2f(50, 50));
    ennemishape.setFillColor(sf::Color::White);
    ennemishape.setPosition(position);
    tag = "Ennemi";
}

void Ennemi::update(float deltaTime) {
    velocity.x = -speed;
    position += velocity * deltaTime;
    ennemishape.setPosition(position);
}

void Ennemi::draw(sf::RenderWindow& window) const {
    window.draw(ennemishape);
}

//bool Ennemi::checkCollision(const Entity& other) const {
//	const Player* player = dynamic_cast<const Player*>(&other);
//    if (player)
//    {
//        return ennemishape.getGlobalBounds().intersects(player->playershape.getGlobalBounds());
//    }
//
//	const Ennemi*ennemi = dynamic_cast<const Ennemi*>(&other);
//	if (ennemi)
//	{
//		return ennemishape.getGlobalBounds().intersects(ennemi->ennemishape.getGlobalBounds());
//	}
//	return false;
//}

sf::FloatRect Ennemi::getGlobalBounds() const {
    return ennemishape.getGlobalBounds();
};