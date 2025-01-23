#include "Potion.h"

Potion::Potion(int posX, int posY, Player _player) :player(_player){
    position = sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY));
    potionShape.setSize(sf::Vector2f(30.0f, 30.0f));
    potionShape.setFillColor(sf::Color::Green);
    potionShape.setPosition(position);
    effectClock.restart();
    effectActive = false;
	anyPotionActive = false;
	originalSpeed = player.speed;

    tag = "Potion";
}

void Potion::interact(Player& player) {
    if (!effectActive && !anyPotionActive) {
        effectActive = true;
        anyPotionActive = true;
        player.buff();
        //player.speed *= 2;
        effectClock.restart();
        std::cout << "Potion consommée. Vitesse du joueur doublee." << std::endl;
    }
}
void Potion::update(float deltaTime) {
    player.buff();
    std::cout << "Update called. Elapsed time: " << effectClock.getElapsedTime().asSeconds() << "s, Effect duration: " << effectDuration.asSeconds() << "s" << std::endl;
    if (effectActive && effectClock.getElapsedTime() > effectDuration) {
        
        effectActive = false;
        anyPotionActive = false;
		player.speed = originalSpeed;
        std::cout << "Effet de la potion termine. Vitesse du joueur reinitialisee." << std::endl;
    }
}

void Potion::draw(sf::RenderWindow& window) const {
    window.draw(potionShape);
}

bool Potion::checkCollision(const Entity& other) const {
	return potionShape.getGlobalBounds().intersects(other.getGlobalBounds());
}
sf::FloatRect Potion::getGlobalBounds() const {
    return potionShape.getGlobalBounds();
}

bool Potion::isEffectActive() const {
    return effectActive;
}
bool Potion::isAnyPotionActive() {
    return anyPotionActive;
}

void Potion::setAnyPotionActive(bool active) {
    anyPotionActive = active;
}
Potion::~Potion() {
    std::cout << "Potion supprimee" << std::endl;
}
//void Potion::handleInteractableCollision(Player& player) {
//    if (player.playershape.getGlobalBounds().intersects(this->getGlobalBounds())) {
//        this->interact(player);
//    }
//}