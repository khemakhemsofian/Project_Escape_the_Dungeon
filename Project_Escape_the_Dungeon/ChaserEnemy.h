#ifndef CHASERENEMY_H
#define CHASERENEMY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ennemi.h"

class ChaserEnemy : public Ennemi {
public:
    ChaserEnemy(int posX, int posY, float ennemiSpeed, Player& player);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    //bool checkCollision(const Player& other) const override;
    sf::RectangleShape ennemishape;
	sf::FloatRect getGlobalBounds() const override;

private:
    Player& player;
};
#endif // !CHASERENEMY_H