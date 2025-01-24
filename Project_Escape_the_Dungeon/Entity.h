#ifndef ENTITY_H
#define ENTITY_H
#include "Map.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
public:
    virtual void update(float deltaTime, Map& map) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    std::string tag;
    //virtual bool checkCollision(const Entity& other) const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
};

#endif // ENTITY_H
