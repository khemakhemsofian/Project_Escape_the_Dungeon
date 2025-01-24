#ifndef PATROLLINGENEMY_H
#define PATROLLINGENEMY_H
#include <SFML/Graphics.hpp>
#include "Ennemi.h"

class PatrollingEnemy : public Ennemi {
public:
    PatrollingEnemy(int posX, int posY, float speed, const std::vector<sf::Vector2f>& waypoints,Player& player);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    //bool checkCollision(const Entity& other) const override;
	sf::FloatRect getGlobalBounds() const override;

private:
    std::vector<sf::Vector2f> waypoints;
    size_t currentWaypointIndex;
    Player& player;
};

#endif // PATROLLINGENEMY_H