#include "PatrollingEnemy.h"
#include <cmath>
#include "ChaserEnemy.h"

PatrollingEnemy::PatrollingEnemy(int posX, int posY, float speed, const std::vector<sf::Vector2f>& waypoints,Player& player)
    : Ennemi(posX, posY, speed), waypoints(waypoints), currentWaypointIndex(0),player(player) {
    ennemishape.setSize(sf::Vector2f(50.0f, 50.0f));
    ennemishape.setPosition(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)));
    ennemishape.setFillColor(sf::Color::Blue); 
}

void PatrollingEnemy::update(float deltaTime) {
    if (waypoints.empty()) return;

    sf::Vector2f target = waypoints[currentWaypointIndex];
    sf::Vector2f direction = target - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length; 
    }
    position += direction * speed * deltaTime;

    if (length < speed * deltaTime) {
        currentWaypointIndex = (currentWaypointIndex + 1) % waypoints.size();
    }
    ennemishape.setPosition(position);
    //if (checkCollision(player))
    //{
    //    std::cout << "patrol t'a toucher ahah" << std::endl;
    //}
}

void PatrollingEnemy::draw(sf::RenderWindow& window) const {
    window.draw(ennemishape);
}

//bool PatrollingEnemy::checkCollision(const Entity& other) const {
//    return ennemishape.getGlobalBounds().intersects(other.getGlobalBounds());
//}

sf::FloatRect PatrollingEnemy::getGlobalBounds() const {
	return ennemishape.getGlobalBounds();
}