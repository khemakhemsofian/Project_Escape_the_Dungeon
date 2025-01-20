#ifndef CHASERENEMY_H
#define CHASERENEMY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Ennemi.h"

class ChaserEnemy : public Ennemi {
public:
    ChaserEnemy(int posX, int posY, float ennemiSpeed, Player& player);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    bool checkCollision(const Entity& other) const override;
    sf::RectangleShape ennemishape;

private:
    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity;
    Player& player;
};
#endif // !CHASERENEMY_H