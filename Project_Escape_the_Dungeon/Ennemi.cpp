#include "Ennemi.h"
#include "Objet.h"
#include "Player.h"
	
	
Ennemi::Ennemi(int posX, int posY, float ennemiSpeed) {
	position = sf::Vector2f(posX, posY);
	velocity = sf::Vector2f(0.0f, 0.0f);
	speed = ennemiSpeed;
	ennemishape.setSize(sf::Vector2f(50, 50));
	ennemishape.setFillColor(sf::Color::Red);
	ennemishape.setPosition(position);
	tag = "Ennemi";
}

void Ennemi::update(float deltaTime) {
	velocity.x = speed;
	position += velocity * deltaTime;
	ennemishape.setPosition(position);
	
}

void Ennemi::draw(sf::RenderWindow& window) {
	window.draw(ennemishape);
}
sf::RectangleShape Ennemi::getShape() const {
	return ennemishape;
}