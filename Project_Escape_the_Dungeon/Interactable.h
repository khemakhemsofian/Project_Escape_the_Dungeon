#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h" 


class Interactable : public Entity {
public:
    virtual void interact(Player& player) = 0;
    virtual void update(float deltaTime) override = 0;
    virtual void draw(sf::RenderWindow& window) const override = 0;
    virtual sf::FloatRect getGlobalBounds() const override = 0;
};

#endif // INTERACTABLE_H