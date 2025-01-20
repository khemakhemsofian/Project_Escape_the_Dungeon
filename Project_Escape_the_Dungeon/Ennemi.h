#ifndef ENNEMI_H
#define ENNEMI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Ennemi : public Entity {
public:
    Ennemi(int posX, int posY, float ennemiSpeed);
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    sf::RectangleShape getShape() const; // Ajout de la méthode getShape
private:
    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::RectangleShape ennemishape;
};

#endif // !ENNEMI_H