#ifndef ENNEMI_H
#define ENNEMI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Interactable.h"
class Ennemi : public Entity {
public:
    Ennemi(int posX, int posY, float ennemiSpeed);
   virtual void update(float deltaTime) override; 
    void draw(sf::RenderWindow& window) const override;
    bool checkCollision(const Entity& other) const override;
    sf::FloatRect getGlobalBounds() const override;
    sf::RectangleShape ennemishape;

protected:
    float speed;
    sf::Vector2f position;
    sf::Vector2f velocity;
};

#endif // !ENNEMI_H