#include "PatrollingEnemy.h"
#include <cmath>

PatrollingEnemy::PatrollingEnemy(int posX, int posY, float speed, const std::vector<sf::Vector2f>& waypoints)
    : Ennemi(posX, posY, speed), waypoints(waypoints), currentWaypointIndex(0) {
    ennemishape.setSize(sf::Vector2f(50.0f, 50.0f));
    ennemishape.setPosition(sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY)));
    ennemishape.setFillColor(sf::Color::Blue); // Couleur bleue pour PatrollingEnemy
}

void PatrollingEnemy::update(float deltaTime) {
    if (waypoints.empty()) return;

    sf::Vector2f target = waypoints[currentWaypointIndex];
    sf::Vector2f direction = target - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length; // Normaliser la direction
    }
    position += direction * speed * deltaTime;

    if (length < speed * deltaTime) {
        currentWaypointIndex = (currentWaypointIndex + 1) % waypoints.size();
    }

    ennemishape.setPosition(position);
}

void PatrollingEnemy::draw(sf::RenderWindow& window) const {
    window.draw(ennemishape);
}

bool PatrollingEnemy::checkCollision(const Entity& other) const {
    // Implémentez la détection de collision ici
    return false;
}